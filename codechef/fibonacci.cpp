#include <iostream>
#include <unistd.h>

void fibonacci(int data) {
    int a = 0, b = 1;
    for (int i = 0; i < data; i++) {
        std::cout << a << " ";
        int temp = a;
        a = b;
        b += temp;
    }
    std::cout << std::endl;
}

int main() {
    pid_t data = fork();
    if (data == 0) {
        execl("./factorial", "factorial", "5", NULL);
    } else {
        fibonacci(5);
    }
    return 0;
}