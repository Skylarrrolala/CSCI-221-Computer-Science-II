# Lab 9 Guidance: Dynamic Arrays

**Due**: January 22, 2026, 6:00 PM  
**Attempts**: 1 only - make it count!  
**Topics**: Dynamic memory allocation, pointers, arrays

## 📖 What You Need to Know First

Before starting this lab, make sure you understand:
- ✅ Dynamic memory allocation (`new` and `delete`)
- ✅ Pointers and how they work
- ✅ Arrays (static and dynamic)
- ✅ Pass-by-reference (`&` parameter)
- ✅ How to return pointers from functions

**Review**: [Dynamic Memory Management](../topics/02-dynamic-memory.md)

## 🎯 Lab Overview

You're going to create functions that emulate how a **vector** works internally - specifically, how it grows and shrinks dynamically.

### What You're Building:
1. A dynamic array of strings (5 names initially)
2. `addEntry()` - grows the array by 1 and adds a new string
3. `deleteEntry()` - shrinks the array by 1 and removes a string
4. A test program that uses these functions

### The Big Picture:
This lab teaches you what happens "under the hood" when you use `vector::push_back()` and `vector::erase()`.

## 🤔 Understanding the Requirements

### Starting Setup:
```
Initial array with 5 names:
["Alice", "Bob", "Charlie", "Diana", "Eve"]
size = 5
```

### What addEntry() Must Do:

**Think about it step-by-step:**
1. You have an array of size 5
2. You want to add a 6th element
3. But arrays have fixed size! Can't just add to the end
4. Solution: Create a NEW, bigger array

**The Process:**
```
Old array (size 5): ["Alice", "Bob", "Charlie", "Diana", "Eve"]

Step 1: Create new array of size 6
Step 2: Copy all 5 elements to new array
Step 3: Add new entry at position 5
Step 4: Delete old array (prevent memory leak!)
Step 5: Return pointer to new array
```

### What deleteEntry() Must Do:

**Think about it:**
1. Find the entry to delete
2. If not found, return original array unchanged
3. If found, create smaller array without that entry

**The Process:**
```
Original: ["Alice", "Bob", "Charlie", "Diana", "Eve"]
Delete "Charlie"

Step 1: Find "Charlie" (it's at index 2)
Step 2: Create new array of size 4
Step 3: Copy elements before "Charlie": ["Alice", "Bob"]
Step 4: Copy elements after "Charlie": ["Diana", "Eve"]
Step 5: Delete old array
Step 6: Return pointer to new array

Result: ["Alice", "Bob", "Diana", "Eve"]
```

## 📝 Planning Your Approach

### Step 1: Understand the Function Signatures

```cpp
PSEUDOCODE:

FUNCTION addEntry(dynamicArray: pointer to string, 
                  size: reference to int, 
                  newEntry: string) -> pointer to string:
    // Takes current array, current size, and new entry
    // Returns pointer to NEW array
    // Modifies size (that's why it's by reference)
```

**Key Questions to Answer:**
- Why is `dynamicArray` a pointer? (It's a dynamic array)
- Why is `size` a reference? (We need to modify the original size variable)
- What do we return? (Pointer to the new array)

### Step 2: Plan addEntry() in Pseudocode

**YOUR TASK:** Write pseudocode for addEntry() before coding!

**Hint - Think through these steps:**
```
FUNCTION addEntry(oldArray, size, newEntry):
    // 1. What's the new size?
    
    // 2. How do you create a new array of the new size?
    
    // 3. How do you copy all elements from old to new?
    
    // 4. Where does newEntry go in the new array?
    
    // 5. What do you do with the old array?
    
    // 6. What do you do with the size parameter?
    
    // 7. What do you return?
```

**Don't look at the solution yet! Try writing this yourself first.**

<details>
<summary>Click here only after you've tried yourself</summary>

```
PSEUDOCODE for addEntry:

FUNCTION addEntry(oldArray: string*, size: int&, newEntry: string) -> string*:
    CREATE newArray with size (size + 1)
    
    FOR i from 0 to size-1:
        COPY oldArray[i] to newArray[i]
    
    SET newArray[size] = newEntry
    
    DELETE oldArray
    
    INCREMENT size
    
    RETURN newArray
```

</details>

### Step 3: Plan deleteEntry() in Pseudocode

**YOUR TASK:** Plan this one too!

**Think about:**
- How do you find the entry to delete?
- What if it's not found?
- How do you copy elements while skipping one?

**Structure:**
```
FUNCTION deleteEntry(oldArray, size, entryToDelete):
    // 1. Search for entryToDelete in the array
    
    // 2. If not found, what do you return?
    
    // 3. If found, what's the new size?
    
    // 4. How do you create the new array?
    
    // 5. How do you copy elements, skipping the deleted one?
    
    // 6. What do you do with the old array?
    
    // 7. What do you update? What do you return?
```

<details>
<summary>Click here only after trying yourself</summary>

```
PSEUDOCODE for deleteEntry:

FUNCTION deleteEntry(oldArray: string*, size: int&, entryToDelete: string) -> string*:
    FIND index of entryToDelete in oldArray
    
    IF not found:
        RETURN oldArray  // Return unchanged
    
    CREATE newArray with size (size - 1)
    
    SET newIndex = 0
    FOR i from 0 to size-1:
        IF i != index_to_delete:
            COPY oldArray[i] to newArray[newIndex]
            INCREMENT newIndex
    
    DELETE oldArray
    
    DECREMENT size
    
    RETURN newArray
```

</details>

## 🧪 Testing Strategy

### Test Cases You MUST Try:

**Test addEntry():**
1. Add to initial array (5 → 6 elements)
2. Add multiple times in a row (6 → 7 → 8)
3. Add to empty array (if you test that scenario)

**Test deleteEntry():**
1. Delete existing entry (should work)
2. Delete non-existing entry (should return unchanged)
3. Delete first element
4. Delete last element
5. Delete middle element
6. Delete until only one element left
7. Try to delete from array with one element

**Test Memory:**
```bash
# Compile
g++ -Wall -Wextra lab09.cpp -o lab09

# Run with valgrind to check for memory leaks
valgrind --leak-check=full ./lab09
```

### What Your Test Program Should Do:

```
PSEUDOCODE for main():

CREATE initial array with 5 names
SET size = 5

DISPLAY initial array

// Test adding
CALL addEntry and assign result back to array
DISPLAY array after adding

// Test deleting existing
CALL deleteEntry and assign result back to array  
DISPLAY array after deleting

// Test deleting non-existing
CALL deleteEntry with fake name
DISPLAY array (should be unchanged)

// Clean up
DELETE final array
```

## ⚠️ Common Pitfalls

### Pitfall 1: Forgetting to Delete Old Array
```cpp
// WRONG - Memory leak!
string* addEntry(string* arr, int& size, string entry) {
    string* newArr = new string[size + 1];
    // ... copy elements ...
    // Forgot to delete arr!
    return newArr;
}

// RIGHT
string* addEntry(string* arr, int& size, string entry) {
    string* newArr = new string[size + 1];
    // ... copy elements ...
    delete[] arr;  // Clean up!
    return newArr;
}
```

### Pitfall 2: Not Reassigning in Main
```cpp
// WRONG - Doesn't update the array!
addEntry(myArray, size, "Frank");

// RIGHT - Must assign the return value!
myArray = addEntry(myArray, size, "Frank");
```

### Pitfall 3: Using delete Instead of delete[]
```cpp
// WRONG - Undefined behavior!
delete oldArray;  // Array needs delete[]

// RIGHT
delete[] oldArray;
```

### Pitfall 4: Modifying Size Incorrectly
```cpp
// WRONG - Size not updated!
string* addEntry(string* arr, int size, string entry) {
    // size is not a reference, changes won't persist
}

// RIGHT
string* addEntry(string* arr, int& size, string entry) {
    // size is a reference, changes persist
    size++;
}
```

## 🎯 Step-by-Step Implementation Guide

**Follow these steps IN ORDER:**

### Step 1: Create Initial Array (in main)
Start with just creating and displaying the initial 5-name array.
Test: Does it compile? Does it display correctly?

### Step 2: Implement addEntry() Shell
Write the function signature and just return the old array.
Test: Does it compile?

### Step 3: Complete addEntry() Logic
Fill in the function following your pseudocode.
Test: Add one entry. Does array grow? Print to verify.

### Step 4: Test addEntry() Thoroughly
Add multiple entries. Check size. Verify no memory leaks.

### Step 5: Implement deleteEntry() Shell
Function signature, return old array.

### Step 6: Complete deleteEntry() Logic
Implement search and deletion logic.
Test: Delete one entry. Verify it works.

### Step 7: Test deleteEntry() Thoroughly
Test all edge cases listed above.

### Step 8: Final Testing
Run complete program with valgrind. No leaks? You're ready!

## 🔍 Debugging Tips

### If Your Array Isn't Growing:
- Did you reassign the return value in main?
- Did you increment size?
- Print size before and after to verify

### If You Have Memory Leaks:
- Are you deleting the old array in both functions?
- Are you using `delete[]` not `delete`?
- Are you deleting the final array before program ends?

### If Delete Isn't Working:
- Print the index you found - is it correct?
- Check your loop logic for copying
- Make sure you're not copying the deleted element

## ✅ Before You Submit

**Checklist:**
- [ ] Program compiles with no errors or warnings
- [ ] addEntry() works correctly
- [ ] deleteEntry() works for existing entries
- [ ] deleteEntry() handles non-existing entries
- [ ] Size is updated correctly
- [ ] No memory leaks (run valgrind!)
- [ ] Code is commented and readable
- [ ] Tested with various inputs
- [ ] Output clearly shows what's happening

## 🚀 You're Ready When...

✅ You can explain why we need to create a new array  
✅ You understand the difference between `delete` and `delete[]`  
✅ You know why size must be passed by reference  
✅ You can trace through your code with a specific example  
✅ Valgrind shows "no leaks are possible"

---

**Take your time, test thoroughly, and remember - you only get ONE attempt!** 💪

**Questions?** Review the [Dynamic Memory](../topics/02-dynamic-memory.md) guide again, and work through the examples step by step.
