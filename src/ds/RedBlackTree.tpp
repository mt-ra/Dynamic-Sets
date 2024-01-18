#include "ds/RedBlackTree.h"

#include <iostream>
#include <memory>

template<typename T>
ds::RedBlackTree<T>::RedBlackTree() {
    nil = std::make_shared<Element>();
    nil->color = BLACK;
    nil->is_nil = true;

    root = nil;
}

template<typename T>
ds::RedBlackTree<T>::~RedBlackTree() {

}

//// Query Operations ////

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::search(int key) {
    return search_helper(root, key);
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::minimum() {
    return minimum_helper(root);
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::maximum() {
    return maximum_helper(root);
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::successor(std::shared_ptr<Element> element) {
    return nullptr;
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::predecessor(std::shared_ptr<Element> element) {
    return nullptr;
}

//// Modifying Operations ////
template<typename T>
void ds::RedBlackTree<T>::insert(std::shared_ptr<Element> element) {
    if (root == nil) {
        root = element;
        element->left = nil;
        element->right = nil;
    } else {
        root = insert_helper(root, element);
    }
}

template<typename T>
void ds::RedBlackTree<T>::remove(std::shared_ptr<Element> element) {

}

//// Helper functions ////

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::search_helper(std::shared_ptr<Element> root, int key) {
    if (root == nil) {
        return nullptr;
    } else if (key == root->key) {
        return root;
    } else if (key < root->key) {
        return search_helper(root->left_child, key);
    } else {
        return search_helper(root->right_child, key);
    }
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::minimum_helper(std::shared_ptr<Element> root) {
    if (root->left_child == nil) {
        return root;
    } else {
        return minimum_helper(root->left_child);
    }
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::maximum_helper(std::shared_ptr<Element> root) {
    if (root->right_child == nil) {
        return root;
    } else {
        return maximum_helper(root->right_child);
    }
}



template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::rotate_left(std::shared_ptr<Element> root) {
    if (root->right_child == nil) {
        return nullptr;
    }
    auto new_root = root->right_child;
    root->right_child = new_root->left_child;
    new_root->left_child = root;
    return new_root;
}

template<typename T>
std::shared_ptr<typename ds::RedBlackTree<T>::Element> ds::RedBlackTree<T>::rotate_right(std::shared_ptr<Element> root) {
    if (root->left_child == nil) {
        return nullptr;
    }
    auto new_root = root->left_child;
    root->left_child = new_root->right_child;
    new_root->right_child = root;
    return new_root;
}
