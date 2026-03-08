#include <iostream>
#include <cstring>
#include <vector>
#include <chrono>

class MyString {
private:
    char* data;
    size_t length;

public:
    // 1. Default Constructor
    MyString() : data(nullptr), length(0) {}

    // 2. Parameterized Constructor
    MyString(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
        std::cout << "Constructed: " << data << "\n";
    }

    // 3. Destructor
    ~MyString() {
        delete[] data;
    }

    // =========================================================================
    // TODO 1: Implement the Copy Constructor (Deep Copy)
    // Signature: MyString(const MyString& other)
    // =========================================================================
    MyString(const MyString& other){
        this->length = other.length;
        if(other.data){
            data = new char[length+1];
            std::strcpy(data, other.data);
        }else data = nullptr;
        std::cout << "Copy constructor triggered " <<std::endl;
    }

    // =========================================================================
    // TODO 2: Implement the Move Constructor (Steal the pointer)
    // Signature: MyString(MyString&& other) noexcept
    // Hint: Don't forget to set other.data to nullptr!
    // =========================================================================

    MyString(MyString&& other) noexcept : data(other.data), length(other.length){
        other.data= nullptr;
        other.length = 0;
        std::cout<< "Move constructor triggered"<<std::endl;
    }
    // =========================================================================
    // TODO 3: Implement the Copy Assignment Operator (Deep Copy)
    // Signature: MyString& operator=(const MyString& other)
    // Hint: Check for self-assignment (if this == &other)
    // =========================================================================
    MyString& operator=(const MyString& other){
        if(this != &other){ // self assignment guard
            length = other.length;
            if(other.data){
                data = new char[length+1];
                std::strcpy(data, other.data);
            }else data= nullptr;
        }
        std::cout << "Copy assignment triggered" <<std::endl;
        return *this;
    }
    // =========================================================================
    // TODO 4: Implement the Move Assignment Operator (Steal the pointer)
    // Signature: MyString& operator=(MyString&& other) noexcept
    // =========================================================================
    MyString& operator=(MyString&& other) noexcept {
        if(this != &other){ // self assignment guard
           delete[] data;// clean existing
           
           data = other.data;
           length = other.length;
           
           // nullify the source
           other.data= nullptr;
           other.length = 0;
        }
        std::cout << "Move Assignment triggered" <<std::endl;
        return *this;
    }
    void print() const {
        if (data) std::cout << data << "\n";
        else std::cout << "[Empty/Moved]\n";
    }
};

int main() {
    std::cout << "--- Testing Copy vs Move ---\n";

    MyString str1("Hello Backend World");

    std::cout << "\nAttempting Copy:\n";
    MyString str2 = str1; // Should trigger Copy Constructor

    std::cout << "\nAttempting Move:\n";
    MyString str3 = std::move(str1); // Should trigger Move Constructor

    std::cout << "\nFinal States:\n";
    std::cout << "str1: "; str1.print(); // Should be empty
    std::cout << "str2: "; str2.print(); // Should have "Hello Backend World"
    std::cout << "str3: "; str3.print(); // Should have "Hello Backend World"

    return 0;
}
