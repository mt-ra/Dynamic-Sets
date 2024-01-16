#pragma once

#include <vector>

namespace ds 
{

template<typename T>
class MaxHeap {
public:
    struct Element {
        int key;
        T satellite_data;
    };

    MaxHeap();
    ~MaxHeap();

    // Query Operations
    Element *maximum();

    // Modifying Operations
    void insert(Element *element);
    void remove(Element *element);

private:
    std::vector<Element *> arr;

};

}

#include "ds/MaxHeap.tpp"