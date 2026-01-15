# Dynamic Memory Management

## 📖 Conceptual Overview

**What is Dynamic Memory?**
Memory allocated at runtime (during program execution) rather than compile time. In C++, we use `new` and `delete` operators to manage heap memory.

**Why Use Dynamic Memory?**
- Size unknown at compile time
- Need data to persist beyond function scope
- Create data structures of variable size
- Efficient memory usage (allocate only what you need)

**The Golden Rule:** Every `new` must have a matching `delete`!

## 🎯 Core Concepts

### 1. Stack vs. Heap Memory

**Understanding the Difference:**
```
STACK (Automatic Memory):
- Allocated at compile time
- Fixed size
- Automatically deallocated when scope ends
- Fast access
- Limited size

HEAP (Dynamic Memory):
- Allocated at runtime using 'new'
- Flexible size
- Must manually deallocate using 'delete'
- Slower access than stack
- Larger available size
```

### 2. Pointer Basics

**PSEUDOCODE Pattern:**
```
// Declare pointer
DECLARE pointerVariable -> dataType

// Allocate memory
SET pointerVariable = ALLOCATE memory for dataType

// Use the pointer
SET *pointerVariable = value  // Dereference to assign
GET value = *pointerVariable  // Dereference to read

// Deallocate memory
DEALLOCATE pointerVariable
SET pointerVariable = NULL  // Prevent dangling pointer
```

**Step-by-Step Thinking:**
1. What type of data will the pointer point to?
2. When should memory be allocated? (Constructor? Function call?)
3. How will the pointer be used?
4. When should memory be deallocated? (Destructor? Function end?)
5. What happens if allocation fails?

### 3. Dynamic Single Variables

**PSEUDOCODE:**
```
// Allocate single variable
FUNCTION allocateSingleVariable():
    DECLARE ptr -> int
    SET ptr = ALLOCATE memory for int
    
    IF ptr == NULL:  // Check allocation success
        HANDLE error (throw exception, return error code)
    
    SET *ptr = value
    
    // ... use ptr ...
    
    DEALLOCATE ptr
    SET ptr = NULL
    RETURN success
```

**Edge Cases:**
- Allocation failure (out of memory)
- Forgetting to delete (memory leak)
- Using after delete (dangling pointer)
- Double delete (undefined behavior)

### 4. Dynamic Arrays

**PSEUDOCODE Pattern:**
```
// Allocate array
FUNCTION allocateDynamicArray(size):
    IF size <= 0:  // Edge case: invalid size
        RETURN NULL
    
    DECLARE arr -> array of dataType
    SET arr = ALLOCATE array of size elements
    
    IF arr == NULL:  // Check allocation
        HANDLE error
    
    // Initialize array
    FOR i from 0 to size-1:
        SET arr[i] = default_value
    
    RETURN arr

// Deallocate array
FUNCTION deallocateDynamicArray(arr):
    IF arr != NULL:
        DEALLOCATE array arr  // Use delete[] not delete
        SET arr = NULL
```

**Critical Points:**
- Use `delete[]` for arrays, not `delete`
- Track array size separately
- Initialize all elements
- Check for NULL before use

### 5. The Big Three (Rule of Three)

**When a class uses dynamic memory, implement:**

**PSEUDOCODE:**
```
CLASS DynamicClass:
    PRIVATE:
        pointer data
        int size
    
    PUBLIC:
        // 1. DESTRUCTOR - Clean up
        DESTRUCTOR ~DynamicClass():
            IF data != NULL:
                DEALLOCATE array data
                SET data = NULL
        
        // 2. COPY CONSTRUCTOR - Deep copy
        CONSTRUCTOR DynamicClass(other):
            SET size = other.size
            IF other.data != NULL:
                ALLOCATE array data of size elements
                FOR i from 0 to size-1:
                    COPY data[i] = other.data[i]
            ELSE:
                SET data = NULL
        
        // 3. ASSIGNMENT OPERATOR - Deep copy + cleanup
        FUNCTION operator=(other) -> reference:
            IF this != &other:  // Self-assignment check
                // Clean up existing memory
                IF data != NULL:
                    DEALLOCATE array data
                
                // Copy from other
                SET size = other.size
                IF other.data != NULL:
                    ALLOCATE array data of size elements
                    FOR i from 0 to size-1:
                        COPY data[i] = other.data[i]
                ELSE:
                    SET data = NULL
            
            RETURN *this
```

**Why Each is Needed:**
- **Destructor**: Prevent memory leaks
- **Copy Constructor**: Prevent shallow copy issues
- **Assignment Operator**: Prevent shallow copy + handle self-assignment

## 💡 Step-by-Step Example: Dynamic Array Class

**Step 1: Identify Requirements**
- Store integers in dynamic array
- Allow resize
- Automatic cleanup
- Safe copying

**Step 2: Design the Class**
```
PSEUDOCODE:

CLASS IntArray:
    PRIVATE:
        int* data       // Pointer to dynamic array
        int capacity    // Current allocated size
        int count       // Number of elements actually used
    
    PUBLIC:
        // Constructor
        CONSTRUCTOR IntArray(initialCapacity):
            IF initialCapacity <= 0:
                SET capacity = 10  // Default size
            ELSE:
                SET capacity = initialCapacity
            
            ALLOCATE data array of capacity ints
            SET count = 0
            
            IF data == NULL:
                THROW memory allocation error
            
            // Initialize to zero
            FOR i from 0 to capacity-1:
                SET data[i] = 0
        
        // Destructor
        DESTRUCTOR ~IntArray():
            IF data != NULL:
                DEALLOCATE array data
                SET data = NULL
        
        // Copy Constructor
        CONSTRUCTOR IntArray(other):
            SET capacity = other.capacity
            SET count = other.count
            ALLOCATE data array of capacity ints
            
            IF data == NULL:
                THROW memory allocation error
            
            FOR i from 0 to count-1:
                SET data[i] = other.data[i]
        
        // Add element
        FUNCTION add(value) -> void:
            IF count >= capacity:
                CALL resize(capacity * 2)
            
            SET data[count] = value
            INCREMENT count
        
        // Resize (private helper)
        FUNCTION resize(newCapacity) -> void:
            IF newCapacity <= count:
                newCapacity = count * 2  // Must fit existing data
            
            ALLOCATE newData array of newCapacity ints
            
            // Copy existing data
            FOR i from 0 to count-1:
                SET newData[i] = data[i]
            
            // Clean up old memory
            DEALLOCATE array data
            SET data = newData
            SET capacity = newCapacity
```

**Step 3: Edge Cases to Consider**
- Empty array (count = 0)
- Adding to full array → resize needed
- Copy empty array
- Resize to smaller capacity
- Self-assignment
- Deleting NULL pointer
- Access out of bounds

**Step 4: Implement and Test (YOUR TURN!)**

## 🧪 Testing Ideas

**Memory Management Tests:**
```
1. Allocation Test:
   - Create object with dynamic memory
   - Verify memory allocated (not NULL)
   - Verify initialization correct

2. Deallocation Test:
   - Create object, let it go out of scope
   - Use valgrind/memory checker: no leaks?

3. Copy Constructor Test:
   - Create object A with data
   - Create object B as copy of A
   - Modify B's data
   - Verify A's data unchanged (deep copy worked)

4. Assignment Operator Test:
   - Create and populate object A
   - Create object B
   - Assign B = A
   - Modify B, verify A unchanged
   - Test self-assignment (A = A)

5. Resize Test:
   - Fill array to capacity
   - Add one more element → triggers resize
   - Verify all data preserved
   - Verify new capacity correct

6. Edge Cases:
   - Zero size allocation
   - Very large allocation
   - Multiple copies/assignments
   - Copying empty object
```

## 📊 Complexity Analysis

**Dynamic Memory Operations:**
- `new` single variable: O(1)
- `new` array of size n: O(n) - must allocate space
- `delete` single variable: O(1)
- `delete[]` array: O(n) - must deallocate each element if complex type
- Copy array: O(n) - must copy each element
- Resize with copy: O(n) - copy all elements to new memory

**Space Complexity:**
- Dynamic allocation: O(n) where n is requested size
- Temporary during resize: O(n) - briefly hold old and new

## ⚠️ Common Pitfalls

### 1. Memory Leaks
```
BAD:
    ALLOCATE ptr = new int(5)
    ptr = new int(10)  // Leak! Lost access to first allocation
    // First 'new' never deleted

GOOD:
    ALLOCATE ptr = new int(5)
    DEALLOCATE ptr
    ALLOCATE ptr = new int(10)
    DEALLOCATE ptr
```

### 2. Dangling Pointers
```
BAD:
    ALLOCATE ptr = new int(5)
    DEALLOCATE ptr
    SET *ptr = 10  // ERROR! Using deleted memory

GOOD:
    ALLOCATE ptr = new int(5)
    DEALLOCATE ptr
    SET ptr = NULL
    IF ptr != NULL:
        SET *ptr = 10
```

### 3. Shallow Copy Problem
```
BAD (Default copy):
    Object A has pointer to array
    Object B = A  // Both point to SAME array!
    Modify B → also modifies A
    Delete A → B has dangling pointer!

GOOD (Deep copy):
    Object A has pointer to array
    Object B = A using copy constructor
    B gets its OWN copy of array
    Modify B → A unaffected
    Delete A → B still valid
```

### 4. Wrong Delete
```
BAD:
    ALLOCATE arr = new int[10]
    DELETE arr  // Should be delete[]!

GOOD:
    ALLOCATE arr = new int[10]
    DELETE[] arr
```

## 🎯 Practice Exercises

**Exercise 1: Dynamic String Class**
Create a class that:
- Stores C-string in dynamic memory
- Implements Big Three
- Provides length(), concatenate(), substring()

Consider:
- Empty string?
- Very long string?
- Concatenating to empty?

**Exercise 2: Resizable ArrayList**
Build generic resizable array with:
- Add, remove, get operations
- Automatic resizing when full
- Shrink when largely empty

Edge cases:
- Remove from empty?
- Access out of bounds?
- When to shrink?

**Exercise 3: Matrix Class**
2D dynamic array with:
- Rows and columns
- Safe indexing
- Matrix operations (add, multiply)

Consider:
- 0x0 matrix?
- Different dimensions?
- Memory cleanup in destructor?

## 🔑 Key Takeaways

1. **Always pair new with delete** (new[] with delete[])
2. **Implement Big Three** for classes with pointers
3. **Check allocation success** before using
4. **Initialize all allocated memory**
5. **Set pointers to NULL after delete**
6. **Deep copy, not shallow copy**
7. **Use memory checkers** (valgrind) to find leaks
8. **Consider smart pointers** (modern C++) for safety

## 🚀 Implementation Challenge

Implement the IntArray class in C++:
1. Write the class with all Big Three
2. Add bounds checking for array access
3. Implement resize functionality
4. Write comprehensive tests
5. Run valgrind to verify no leaks

**Bonus Challenge:** Add exception handling for allocation failures

## 📚 Related Topics
- Previous: [Classes](01-classes.md) - basic class structure
- Next: [Templates](03-templates.md) - generic dynamic structures
- See also: [Linked Lists](04-linked-lists.md) - alternative to dynamic arrays

---
**Remember:** Memory management is about responsibility. You allocate it, you deallocate it!
