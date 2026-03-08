#include <arpa/inet.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <unistd.h>

using namespace std;

// Change this to the Server's IP address if running on different machines
#define IP "10.57.97.253" 
#define PORT 8080
#define BUFFER_SIZE 4096

void sendFile(int sock, const string &filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Cannot open " << filename << endl;
        return;
    }

    in.seekg(0, ios::end);
    long size = in.tellg();
    in.seekg(0);

    send(sock, &size, sizeof(size), 0);

    char buffer[BUFFER_SIZE];
    while (!in.eof()) {
        in.read(buffer, sizeof(buffer));
        int bytesRead = in.gcount();
        if (bytesRead > 0) {
            send(sock, buffer, bytesRead, 0);
        }
    }
    cout << "[Client] Code sent to server.\n";
}

void receiveResult(int sock) {
    long size;
    recv(sock, &size, sizeof(size), 0);

    // We can print directly to console instead of saving to file
    // so it looks like a real terminal output
    char buffer[BUFFER_SIZE];
    long received = 0;

    cout << "\n========== SERVER OUTPUT ==========\n";
    while (received < size) {
        int bytesToRead = min((long)sizeof(buffer), size - received);
        int bytes = recv(sock, buffer, bytesToRead, 0);
        if (bytes <= 0) break;
        
        // Print buffer contents to stdout
        cout.write(buffer, bytes);
        received += bytes;
    }
    cout << "\n===================================\n";
}

int main() {
    while(true) {
        cout << "\nEnter '1' to submit 'submit.cpp' to the server: ";
        int cmd;
        cin >> cmd;
        if(cmd != 1) continue;

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);
        inet_pton(AF_INET, IP, &addr.sin_addr);

        if (connect(sock, (sockaddr *)&addr, sizeof(addr)) < 0) {
            cerr << "Connection Failed\n";
            continue;
        }

        // 1. Send the source code
        sendFile(sock, "submit.cpp");

        // 2. Receive the result (Compilation errors or Program Output)
        receiveResult(sock);

        close(sock);
    }
    return 0;
}