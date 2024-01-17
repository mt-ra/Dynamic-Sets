#include "ds/MaxHeap.h"

#include <iostream>
#include <memory>
#include <vector>

template<typename T>
ds::MaxHeap<T>::MaxHeap() {
    arr = std::vector<std::shared_ptr<Element>>();
}

template<typename T>
ds::MaxHeap<T>::~MaxHeap() {
}

//// Query Operations ////

template<typename T>
std::shared_ptr<typename ds::MaxHeap<T>::Element> ds::MaxHeap<T>::maximum() {
    return arr.front();
}

//// Modifying Operations ////

template<typename T>
void ds::MaxHeap<T>::insert(std::shared_ptr<ds::MaxHeap<T>::Element> element) {
    arr.push_back(element);

    element->position = arr.size() - 1;
    while (element->position != 0) {
        auto parent = MaxHeap<T>::parent(element);
        if (element->key > arr[parent->position]->key) {
            std::swap(arr[element->position], arr[parent->position]);
            std::swap(element->position, parent->position);
        } else {
            break;
        }
    }
}

template<typename T>
void ds::MaxHeap<T>::remove(std::shared_ptr<ds::MaxHeap<T>::Element> element) {

    auto old_back = arr.back();

    std::swap(arr[element->position], arr[old_back->position]);
    arr.pop_back();
    old_back->position = element->position;

    auto left_child = MaxHeap<T>::left_child(old_back);
    auto right_child = MaxHeap<T>::right_child(old_back);

    while (left_child != nullptr) {
        auto preferred_child = left_child;
        if (right_child != nullptr && right_child->key > left_child->key) {
            preferred_child = right_child;
        }

        if (preferred_child->key > old_back->key) {
            std::swap(arr[preferred_child->position], arr[old_back->position]);
            std::swap(preferred_child->position, old_back->position);
        } else {
            break;
        }

        left_child = MaxHeap<T>::left_child(old_back);
        right_child = MaxHeap<T>::right_child(old_back);
    }
}

//// Private Methods ////

template<typename T>
std::shared_ptr<typename ds::MaxHeap<T>::Element> ds::MaxHeap<T>::parent(std::shared_ptr<typename ds::MaxHeap<T>::Element> element) {
    if (element->position == 0) {
        return nullptr;
    } else {
        return arr[(element->position - 1) / 2];
    }
}

template<typename T>
std::shared_ptr<typename ds::MaxHeap<T>::Element> ds::MaxHeap<T>::left_child(std::shared_ptr<typename ds::MaxHeap<T>::Element> element) {
    size_t left_child_position = 2 * element->position + 1;
    if (left_child_position >= arr.size()) {
        return nullptr;
    } else {
        return arr[left_child_position];
    }
}

template<typename T>
std::shared_ptr<typename ds::MaxHeap<T>::Element> ds::MaxHeap<T>::right_child(std::shared_ptr<typename ds::MaxHeap<T>::Element> element) {
    size_t right_child_position = 2 * element->position + 2;
    if (right_child_position >= arr.size()) {
        return nullptr;
    } else {
        return arr[right_child_position];
    }
}