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
        Element(int k, T D) : key(k), satellite_data(D) {}
        int key;
        T satellite_data;
        
        // set implementation
        Color color;
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
    std::shared_ptr<Element> nil;
    // extra
};

}

#include "ds/RedBlackTree.tpp"
