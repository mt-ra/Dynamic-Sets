#include "catch2/catch.hpp"

#include <iostream>
#include <string>
#include <memory>

#include "ds/MaxHeap.h"

TEST_CASE("Always True") {
    CHECK(true);
}

TEST_CASE("Identifies maximum element 1") {
    auto heap = ds::MaxHeap<std::string>();

    heap.insert(std::make_shared<ds::MaxHeap<std::string>::Element>(42, "john"));
    heap.insert(std::make_shared<ds::MaxHeap<std::string>::Element>(21, "henry"));
    heap.insert(std::make_shared<ds::MaxHeap<std::string>::Element>(69, "richard"));
    heap.insert(std::make_shared<ds::MaxHeap<std::string>::Element>(13, "george"));
    heap.insert(std::make_shared<ds::MaxHeap<std::string>::Element>(41, "mary"));
    heap.insert(std::make_shared<ds::MaxHeap<std::string>::Element>(50, "elizabeth"));

    auto max = heap.maximum();

    CHECK(max->satellite_data == "richard");
}

TEST_CASE("Identifies maximum element 2") {
    auto heap = ds::MaxHeap<int>();

    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(42, 1521));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(21, 1531));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(69, 2521));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(113, 1511));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(41, 3821));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(50, 0));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(42, 0));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(21, 546));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(119, 549));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(13, 550));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(141, 21));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(50, 2511));

    CHECK(heap.maximum()->satellite_data == 21);
}

TEST_CASE("Using deletion to find second largest element") {
    auto heap = ds::MaxHeap<int>();
    // {}

    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(42, 1141));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(21, 1081));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(69, 1511));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(113, 2521));
    // {113, 69, 42, 21}

    CHECK(heap.maximum()->satellite_data == 2521);

    heap.remove(heap.maximum());
    // {69, 42, 21}

    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(1, 1111));
    // {69, 42, 21, 1}

    CHECK(heap.maximum()->satellite_data == 1511);
}

TEST_CASE("Miscellaneous Test") {
    auto heap = ds::MaxHeap<int>();

    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(42, 0));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(99, 0));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(41, 0));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(50, 0));
    CHECK(heap.maximum()->key == 99);
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(21, 0));
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(69, 0));
    CHECK(heap.maximum()->key == 99);
    heap.remove(heap.maximum());
    CHECK(heap.maximum()->key == 69);
    heap.remove(heap.maximum());
    CHECK(heap.maximum()->key == 50);
    heap.remove(heap.maximum());
    CHECK(heap.maximum()->key == 42);
    heap.insert(std::make_shared<ds::MaxHeap<int>::Element>(30, 0));
    CHECK(heap.maximum()->key == 42);
    heap.remove(heap.maximum());
    CHECK(heap.maximum()->key == 41);
    heap.remove(heap.maximum());
    CHECK(heap.maximum()->key == 30);
    heap.remove(heap.maximum());
    CHECK(heap.maximum()->key == 21);
}