# ds::MaxHeap

Max-heap implemented using a std::vector, where the element at index 0 is the root of the heap. 

Create elements using `std::make_shared<ds::MaxHeap<T>::Element>()`, and insert them into the heap.

Never manually modify the `position` field.

Template parameter `T` represents the type of the satellite data attached to each heap object.

## Member Functions
**Query Operations**
```cpp
std::shared_ptr<ds::MaxHeap<T>::Element> maximum();
```
Returns a pointer to the element in the heap with the greatest key.  
**Modifying Operations**
```cpp
void insert(std::shared_ptr<ds::MaxHeap<T>::Element> element);
```
Given a pointer to an element, inserts element, maintaining heap structure.  

```cpp
void remove(std::shared_ptr<ds::MaxHeap<T>::Element> element);
```
Given a pointer to an element, removes item, maintaining heap structure.  

## Example

```cpp
#include <string>
#include "ds/MaxHeap.md"

struct Person {
    std::string name;
    float gender;
};

void foo() {
    auto heap = ds::MaxHeap<Person>();

    auto element1 = std::make_shared<ds::MaxHeap<Person>::Element>(
        42, 
        {"john", 1}
    );

    auto element2 = std::make_shared<ds::MaxHeap<Person>::Element>(
        69, 
        {"george", 0.98}
    );

    heap.insert(element1);
    heap.insert(element2);

    std::shared_ptr<ds::MaxHeap<Person>::Element> max_element = heap.maximum();

    std::cout << max_element->satellite_data.name << "\n";
    // george

    heap.remove(max_element);

    std::cout << heap.maximum()->key << "\n";
    // 42
}
```