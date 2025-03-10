#include <iostream>

int factorial(int data) {
    int res = 1;
    for (int i = 2; i <= data; i++) res *= i;
    return res;
}
int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    int num = std::atoi(argv[1]);
    std::cout << "Factorial of " << num << " is " << factorial(num) << std::endl;
    return 0;
}