#include "ds/MaxHeap.h"

#include <iostream>

template<typename T>
ds::MaxHeap<T>::MaxHeap() {
    // commentary
    std::cout << "constructing MaxHeap\n";
}

template<typename T>
ds::MaxHeap<T>::~MaxHeap() {
    // commentary
    std::cout << "destructing MaxHeap\n";

}

//// Query Operations ////

template<typename T>
typename ds::MaxHeap<T>::Element *ds::MaxHeap<T>::maximum() {
    return nullptr;
}

//// Modifying Operations ////

template<typename T>
void ds::MaxHeap<T>::insert(MaxHeap<T>::Element *element) {
}

template<typename T>
void ds::MaxHeap<T>::remove(MaxHeap<T>::Element *element) {
}