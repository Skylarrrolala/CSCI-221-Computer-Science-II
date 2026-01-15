# Chapter 9: Pointers and Dynamic Arrays - Concept Notes

## What this chapter is about

Pointers are variables that store memory addresses instead of regular values. They're the foundation for dynamic memory allocation, which lets your programs create arrays and objects whose size can change while the program runs. This chapter teaches you how to use `new` and `delete` to manage memory manually, which is crucial for Lab 9 (dynamic arrays) and Quiz 1. Understanding pointers is essential for everything else in C++ that follows.

## Key ideas in plain words

- **A pointer stores a memory address**, not a value. Think of it like storing a house address instead of the house itself.
- **The `*` operator dereferences a pointer**, meaning it accesses the value at that address.
- **The `&` operator gets the address** of a variable (called the "address-of" operator).
- **Dynamic memory is allocated on the heap** using `new`, and must be freed using `delete` or `delete[]`.
- **Stack memory is automatic** (local variables), but heap memory is manual (you control it).
- **A dynamic array can grow or shrink** at runtime by creating a new array, copying data, and deleting the old one.
- **Memory leaks happen** when you allocate memory with `new` but forget to `delete` it.
- **Dangling pointers** point to memory that's been deleted or deallocated—using them causes crashes.
- **`nullptr` is the safe value** for a pointer that doesn't point anywhere yet (better than NULL or 0).
- **Pointer arithmetic** lets you move through arrays using `ptr++` or `ptr + 5`.

## Tiny C++ examples

### Example 1: Basic pointer usage
```cpp
int x = 42;
int* ptr = &x;        // ptr stores the address of x
cout << *ptr << endl; // prints 42 (dereference to get value)
*ptr = 100;           // changes x to 100
cout << x << endl;    // prints 100
```
**Explanation:** The pointer `ptr` holds the address of `x`. Using `*ptr` accesses or modifies the actual value of `x`.

### Example 2: Dynamic memory allocation
```cpp
int* arr = new int[5];  // create dynamic array of 5 ints
arr[0] = 10;
arr[1] = 20;
// ... use the array ...
delete[] arr;           // MUST free the memory
arr = nullptr;          // good practice: set to nullptr after delete
```
**Explanation:** `new int[5]` allocates memory on the heap for 5 integers. You must use `delete[]` (with brackets) to free array memory, or you'll leak memory.

### Example 3: Resizing a dynamic array
```cpp
int size = 3;
int* oldArray = new int[size]{10, 20, 30};

int newSize = 5;
int* newArray = new int[newSize];  // bigger array
for (int i = 0; i < size; i++) {
    newArray[i] = oldArray[i];     // copy old data
}
newArray[3] = 40;  // add new elements
newArray[4] = 50;

delete[] oldArray;  // free old array
oldArray = newArray;  // point to new array
size = newSize;
```
**Explanation:** To resize, create a new larger array, copy everything from the old array, add new data, then delete the old array and update your pointer.

### Example 4: Pointer and array relationship
```cpp
int* ptr = new int[4]{1, 2, 3, 4};
cout << ptr[2] << endl;    // prints 3 (array notation)
cout << *(ptr + 2) << endl; // prints 3 (pointer arithmetic)
```
**Explanation:** `ptr[2]` and `*(ptr + 2)` are equivalent. Arrays and pointers are closely related in C++.

## How to build something small

Here's how to create a simple resizable array wrapper:

1. **Declare a pointer and size variable** - `int* data = nullptr; int size = 0;`
2. **Allocate initial array** - Use `data = new int[initialSize];` and set `size = initialSize;`
3. **Write a function to add an element** - Create a new array with `size + 1` elements
4. **Copy existing data** - Loop through old array and copy to new array
5. **Add the new element** - Place it at index `size` in the new array
6. **Delete old array** - Use `delete[] data;` to free old memory
7. **Update pointer and size** - Set `data = newArray;` and `size++;`
8. **Clean up at the end** - Before program exits, `delete[] data;` to prevent memory leaks

## Common mistakes to avoid

- **Forgetting `delete[]` for arrays** - If you use `new[]`, you MUST use `delete[]` (with brackets), not just `delete`.
- **Using a pointer after deleting it** - After `delete[] ptr;`, don't access `ptr[0]`. Set `ptr = nullptr;` to be safe.
- **Not initializing pointers** - Always initialize: `int* ptr = nullptr;` not just `int* ptr;` (random address).
- **Deleting the same memory twice** - Double-delete causes crashes. Only delete once, then set to `nullptr`.
- **Memory leaks from losing the pointer** - If you reassign `ptr` without deleting, the old memory is lost forever.
- **Off-by-one errors when copying** - When copying `size` elements, loop from `0` to `size - 1`, not `size`.
- **Mixing `new` and `delete[]`** - Use `delete` for single objects, `delete[]` for arrays. Don't mix them.
- **Accessing out of bounds** - Dynamic arrays don't check bounds. `arr[100]` on a size-5 array will crash or corrupt memory.

## Practice checklist

- [ ] I can explain what a pointer stores and how it differs from a regular variable.
- [ ] I can write code that allocates a dynamic array using `new[]` and frees it with `delete[]`.
- [ ] I can create a new larger array, copy data from an old array, and delete the old one.
- [ ] I can trace a pointer example and predict what gets printed when dereferencing.
- [ ] I understand why memory leaks happen and how to prevent them.
- [ ] I can identify common pointer mistakes (dangling pointers, double delete, no delete).
