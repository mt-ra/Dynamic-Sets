#pragma once

#include <vector>
#include <memory>

namespace ds 
{

template<typename T>
class MaxHeap {
public:
    struct Element {
        Element(int k, T D) : key(k), satellite_data(D) {}
        int key;
        size_t position;
        T satellite_data;
    };

    MaxHeap();
    ~MaxHeap();

    // Query Operations
    std::shared_ptr<Element> maximum();

    // Modifying Operations
    void insert(std::shared_ptr<Element> element);
    void remove(std::shared_ptr<Element> element);

private:
    std::vector<std::shared_ptr<Element>> arr;

    // Private Methods
    std::shared_ptr<Element> parent(std::shared_ptr<Element> element);
    std::shared_ptr<Element> left_child(std::shared_ptr<Element> element);
    std::shared_ptr<Element> right_child(std::shared_ptr<Element> element);

};

}

#include "ds/MaxHeap.tpp"