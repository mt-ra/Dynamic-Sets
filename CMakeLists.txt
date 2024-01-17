cmake_minimum_required(VERSION 3.16)
project(Dynamic_Sets)

include_directories(include)
include_directories(src)
include_directories(test)

file(GLOB SOURCES

)

file(GLOB TEST_SOURCES
    test/test_main.cpp
    test/test_MaxHeap.cpp
    test/test_RedBlackTree.cpp
)

add_executable(app
    ${SOURCES}
    src/main.cpp
)

enable_testing()

add_executable(testapp
    ${SOURCES}
    ${TEST_SOURCES}
)

add_test(NAME COMPLETE_TEST COMMAND testapp)