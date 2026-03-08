#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <unistd.h>

using namespace std;

#define PORT 8080
#define BUFFER_SIZE 4096

// Helper to send a file over the socket
void sendFile(int sock, const string &filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        // If output file doesn't exist, send size 0
        long size = 0;
        send(sock, &size, sizeof(size), 0);
        return;
    }

    in.seekg(0, ios::end);
    long size = in.tellg();
    in.seekg(0);

    // Send file size first
    send(sock, &size, sizeof(size), 0);

    // Send file content
    char buffer[BUFFER_SIZE];
    while (!in.eof()) {
        in.read(buffer, sizeof(buffer));
        int bytesRead = in.gcount();
        if (bytesRead > 0) {
            send(sock, buffer, bytesRead, 0);
        }
    }
    cout << "[Server] Sent execution results (" << size << " bytes).\n";
}

// Helper to receive a file from the socket
void receiveFile(int sock, const string &filename) {
    long size;
    int n = recv(sock, &size, sizeof(size), 0);
    if (n <= 0) return;

    ofstream out(filename, ios::binary | ios::trunc);
    char buffer[BUFFER_SIZE];
    long received = 0;

    while (received < size) {
        int bytesToRead = min((long)sizeof(buffer), size - received);
        int bytes = recv(sock, buffer, bytesToRead, 0);
        if (bytes <= 0) break;
        out.write(buffer, bytes);
        received += bytes;
    }
    cout << "[Server] Received code file.\n";
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // 1. Create Socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 2. Attach socket to port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 3. Listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    cout << "[Server] Listening on port " << PORT << "...\n";

    // 4. Accept loop
    while (true) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }

        cout << "[Server] Connection accepted.\n";

        // Protocol: 
        // 1. Receive Code -> "server_received.cpp"
        receiveFile(new_socket, "server_received.cpp");

        // 2. Execute Bash Script
        cout << "[Server] Running Judge Script...\n";
        system("bash judge.sh");

        // 3. Send Output -> "output.out"
        sendFile(new_socket, "output.out");

        close(new_socket);
        cout << "[Server] Connection closed. Waiting for next...\n";
    }

    return 0;
}