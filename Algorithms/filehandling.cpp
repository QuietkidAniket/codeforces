#include <iostream>
#include <fstream>
#include <sys/stat.h>

int main() {
    const char* filename = "testfile.txt";

    // Create the file
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Failed to create the file." << std::endl;
        return 1;
    }
    outfile.close();

    // Set the file to read-only mode
    if (chmod(filename, S_IRUSR | S_IRGRP | S_IROTH) != 0) {
        std::cerr << "Failed to set the file to read-only mode." << std::endl;
        return 1;
    }
    std::cout << "File set to read-only mode." << std::endl;

    // Attempt to write to the file in read-only mode
    outfile.open(filename, std::ios::app);
    if (!outfile) {
        std::cout << "Unable to write to the file in read-only mode." << std::endl;
    } else {
        outfile << "Attempting to write in read-only mode\n";
        outfile.close();
    }

    // Change the file mode to read and write
    if (chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) != 0) {
        std::cerr << "Failed to change the file mode to read and write." << std::endl;
        return 1;
    }
    std::cout << "File mode changed to read and write." << std::endl;

    // Write to the file in read-write mode
    outfile.open(filename, std::ios::app);
    if (outfile) {
        outfile << "Successfully wrote in read-write mode\n";
        outfile.close();
        std::cout << "Text written to the file in read-write mode." << std::endl;
    } else {
        std::cerr << "Failed to write to the file in read-write mode." << std::endl;
    }

    return 0;
}
