#include <iostream>
#include <string>

#include "ds/MaxHeap.h"

/// STRUCTS //////

// Example data type for satellite data

struct eg_t {
    std::string name;
    int age;
};

// FORWARD DECLARATIONS //////

void demo_MaxHeap();


/// MAIN //////

int main() {
    std::cout << "Hello World!\n";

    demo_MaxHeap();

}

/// FUNCTION DEFINITIONS //////

void demo_MaxHeap() {
    std::cout << "Demonstrating MaxHeap\n";
    auto heap = ds::MaxHeap<eg_t>();
}