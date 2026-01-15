# Chapter 18: Standard Template Library and C++11 - Concept Notes

## What this chapter is about

The Standard Template Library (STL) is a collection of powerful, ready-to-use template classes and functions. Instead of writing your own dynamic arrays or linked lists, you use `vector`, `list`, `map`, and other STL containers. C++11 added modern features like `auto`, range-based for loops, and smart pointers. Quiz 9 covers STL basics, and understanding this chapter makes you a much more productive C++ programmer.

## Key ideas in plain words

- **The STL provides ready-made containers** like `vector` (dynamic array), `list` (linked list), `map` (key-value pairs).
- **`vector` is the most commonly used** - it's like an array that can grow and has built-in functions.
- **Iterators** are objects that point to elements in containers, similar to pointers but more generic.
- **Algorithms** like `sort()`, `find()`, `reverse()` work with STL containers through iterators.
- **`auto` keyword** lets the compiler figure out the type for you - less typing and cleaner code.
- **Range-based for loops** make it easy to iterate over containers: `for (auto x : vec)`.
- **`string` is part of the STL** - it's a container for characters with many helpful methods.
- **No manual memory management needed** - STL containers handle allocation and deallocation automatically.
- **Containers are templated** - you specify the type: `vector<int>`, `list<string>`, etc.
- **C++11 and later add many useful features** - move semantics, lambda functions, smart pointers, nullptr.

## Tiny C++ examples

### Example 1: Using vector
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;       // empty vector
    nums.push_back(10);     // add elements
    nums.push_back(20);
    nums.push_back(30);
    
    cout << "Size: " << nums.size() << endl;  // prints 3
    cout << nums[1] << endl;  // prints 20 (access like array)
    
    nums.pop_back();  // remove last element
    return 0;
}
```
**Explanation:** `vector` grows automatically as you add elements. No need for `new[]` or `delete[]`. Use `push_back()` to add, `pop_back()` to remove from the end.

### Example 2: Range-based for loop (C++11)
```cpp
vector<string> names = {"Alice", "Bob", "Charlie"};

// Old way:
for (int i = 0; i < names.size(); i++) {
    cout << names[i] << endl;
}

// C++11 way:
for (auto name : names) {  // auto deduces type as string
    cout << name << endl;
}

// If you want to modify elements, use reference:
for (auto& name : names) {
    name += " Jr.";
}
```
**Explanation:** Range-based for loops are simpler and safer. `auto` figures out the type for you (here, `string`). Use `auto&` if you want to modify the elements.

### Example 3: Using auto keyword
```cpp
vector<int> numbers = {1, 2, 3, 4, 5};

auto it = numbers.begin();  // it is a vector<int>::iterator
auto sum = 0;               // sum is int (deduced from 0)
auto name = "Bob";          // name is const char*
auto value = 3.14;          // value is double

// Very helpful with complex types:
vector<pair<string, int>> data;
auto item = data.begin();  // don't need to write full iterator type!
```
**Explanation:** `auto` tells the compiler to deduce the type from the initializer. This is especially useful with long type names like STL iterators.

### Example 4: Using iterators
```cpp
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums = {5, 2, 8, 1, 9};

// Find an element
auto it = find(nums.begin(), nums.end(), 8);
if (it != nums.end()) {
    cout << "Found 8 at position " << (it - nums.begin()) << endl;
}

// Sort the vector
sort(nums.begin(), nums.end());

// Print using iterators
for (auto it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";  // dereference like a pointer
}
```
**Explanation:** Iterators act like pointers. `begin()` points to the first element, `end()` points past the last. Algorithms like `find()` and `sort()` work with iterators.

### Example 5: Using map (key-value pairs)
```cpp
#include <map>
#include <string>
using namespace std;

map<string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;
ages["Charlie"] = 22;

cout << "Bob's age: " << ages["Bob"] << endl;  // prints 30

// Check if key exists
if (ages.find("David") != ages.end()) {
    cout << "David found" << endl;
} else {
    cout << "David not found" << endl;
}
```
**Explanation:** `map` stores key-value pairs and keeps them sorted by key. Use `[]` to access or insert. Use `find()` to check if a key exists without adding it.

## How to build something small

Here's how to use a vector to store and manage a list of grades:

1. **Include vector header** - `#include <vector>`
2. **Create a vector** - `vector<double> grades;`
3. **Add some grades** - Use `grades.push_back(85.5);` several times
4. **Print all grades** - Use a range-based for loop: `for (auto g : grades)`
5. **Calculate average** - Sum all elements and divide by `grades.size()`
6. **Find the highest grade** - Use `*max_element(grades.begin(), grades.end())`
7. **Sort the grades** - Use `sort(grades.begin(), grades.end())`
8. **Remove lowest grade** - Find minimum, use `erase()` to remove it

## Common mistakes to avoid

- **Accessing vector elements without checking size** - Before using `vec[i]`, make sure `i < vec.size()`.
- **Forgetting to include headers** - `#include <vector>`, `#include <algorithm>`, `#include <string>`, etc.
- **Using array syntax for insertion** - You can't do `vec[5] = 10` if the vector only has 3 elements. Use `push_back()` or `resize()` first.
- **Modifying container while iterating** - Don't add/remove elements in a range-based for loop or while using iterators (they become invalid).
- **Comparing iterators with NULL** - Use `it != container.end()`, not `it != NULL` or `it != nullptr`.
- **Not using const auto& for read-only loops** - `for (const auto& item : vec)` avoids unnecessary copying.
- **Forgetting std:: namespace** - If you don't use `using namespace std;`, write `std::vector`, `std::cout`, etc.
- **Mixing C arrays and STL** - Prefer vectors over C-style arrays in modern C++. They're safer and more powerful.

## Practice checklist

- [ ] I can create and use a vector to store elements of any type.
- [ ] I can add, remove, and access elements in a vector.
- [ ] I can use a range-based for loop to iterate over a container.
- [ ] I can use auto to simplify type declarations.
- [ ] I understand what iterators are and how to use them.
- [ ] I can use STL algorithms like sort(), find(), and reverse().
