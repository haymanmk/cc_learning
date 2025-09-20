/**
 * @file random_access.cc
 * @brief Random access to static data
 */
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <thread>
#include <chrono>

// static float data
const int DATA_SIZE {100};
static float data[DATA_SIZE];

// Initialize data with some values
void init_data() {
    for (int i = 0; i < DATA_SIZE; ++i) {
        data[i] = static_cast<float>(i) * 1.5f; // Example initialization
    }
}

// Function to get a reference to the data at a specific index
float& get_data_at(int index) {
    if (index < 0 || index >= DATA_SIZE) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// main function
int main() {
    init_data();

    // access data at random indices until user interrupts by pressing Ctrl+C
    try {
        int index;
        int access_count {0};
        while (true) {
            index = rand() % DATA_SIZE; // Random index
            float& value = get_data_at(index);
            // if the times of access equal to DATA_SIZE, print an info and sleep for few milliseconds
            if (++access_count == DATA_SIZE) {
                std::cout << "All data elements have been accessed." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Sleep for 100 ms
                access_count = 0;
            }
            // add time sleep to slow down the output
            // std::cout << "Accessed index: " << index << ", value: " << value << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}