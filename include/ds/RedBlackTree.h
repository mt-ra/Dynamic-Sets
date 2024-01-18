#pragma once

#include <memory>


namespace ds
{

enum Color {
    BLACK,
    RED
};
    
template<typename T>
class RedBlackTree {
public:
    struct Element {
        Element() {}
        Element(int k, T D) : key(k), satellite_data(D) {}
        int key;
        T satellite_data;
        
        // set implementation
        Color color;
        bool is_nil;
        std::shared_ptr<Element> parent;
        std::shared_ptr<Element> left_child;
        std::shared_ptr<Element> right_child;
    };

    RedBlackTree();
    ~RedBlackTree();

    // Query Operations
    std::shared_ptr<Element> search(int key);
    std::shared_ptr<Element> minimum();
    std::shared_ptr<Element> maximum();
    std::shared_ptr<Element> successor(std::shared_ptr<Element> element);
    std::shared_ptr<Element> predecessor(std::shared_ptr<Element> element);

    // Modifying Operations
    void insert(std::shared_ptr<Element> element);
    void remove(std::shared_ptr<Element> element);

private:
    std::shared_ptr<Element> root;
    std::shared_ptr<Element> nil;

    // helper functions
    std::shared_ptr<Element> search_helper(std::shared_ptr<Element> root, int key);
    std::shared_ptr<Element> minimum_helper(std::shared_ptr<Element> root);
    std::shared_ptr<Element> maximum_helper(std::shared_ptr<Element> root);

    std::shared_ptr<Element> insert_helper(std::shared_ptr<Element> root, std::shared_ptr<Element> element);

    std::shared_ptr<Element> rotate_left(std::shared_ptr<Element> root);
    std::shared_ptr<Element> rotate_right(std::shared_ptr<Element> root);
};

}

#include "ds/RedBlackTree.tpp"
