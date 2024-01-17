#include "ds/RedBlackTree.h"

#include <iostream>
#include <memory>

template<typename T>
ds::RedBlackTree<T>::RedBlackTree() {
    // TODO: create the nil node

}

template<typename T>
ds::RedBlackTree<T>::~RedBlackTree() {

}

//// Query Operations ////

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::search(int key) {
    return nullptr;
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::minimum() {
    return nullptr;
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::maximum() {
    return nullptr;
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::successor(std::shared_ptr<typename ds::RedBlackTree<T>::Element> element) {
    return nullptr;
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::predecessor(std::shared_ptr<typename ds::RedBlackTree<T>::Element> element) {
    return nullptr;
}

//// Modifying Operations ////
template<typename T>
void ds::RedBlackTree<T>::insert(std::shared_ptr<typename ds::RedBlackTree<T>::Element> element) {

}

template<typename T>
void ds::RedBlackTree<T>::remove(std::shared_ptr<typename ds::RedBlackTree<T>::Element> element) {

}