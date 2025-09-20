#include <iostream>

void swap();

int buf[2] {1,2};

int main() {
    // Print original values
    std::cout << "Before swap: buf[0] = " << buf[0] << ", buf[1] = " << buf[1] << std::endl;

    swap();

    // Print swapped values
    std::cout << "After swap: buf[0] = " << buf[0] << ", buf[1] = " << buf[1] << std::endl;

    return 0;
}