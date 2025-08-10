#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> p1 = std::make_shared<int>(42);
    std::cout << "Shared pointer value: " << *p1 << std::endl;
    return 0;
}