# Templates and Generic Programming

## 📖 Conceptual Overview

**What are Templates?**
Templates allow you to write code that works with ANY data type. Instead of writing separate functions/classes for int, double, string, etc., write ONE template that works for all.

**Why Use Templates?**
- Code reuse - write once, use with many types
- Type safety - compiler checks types at compile time
- Performance - no runtime overhead (unlike polymorphism)
- Flexibility - works with user-defined types too

**Key Idea:** Let the compiler generate specific versions of your code for each type you use.

## 🎯 Core Concepts

### 1. Function Templates

**PSEUDOCODE Pattern:**
```
TEMPLATE<typename T>
FUNCTION functionName(parameter: T) -> T:
    // Use T as if it were a regular type
    RETURN result of type T
```

**Step-by-Step Thinking:**
1. Identify code that's duplicated across types
2. Replace specific type with template parameter T
3. Ensure operations used work for all types
4. Compiler generates specific version when called

**Example Process:**
```
WITHOUT TEMPLATES (repetitive):
    FUNCTION max_int(a: int, b: int) -> int:
        RETURN (a > b) ? a : b
    
    FUNCTION max_double(a: double, b: double) -> double:
        RETURN (a > b) ? a : b
    
    // Need one for each type!

WITH TEMPLATE (generic):
    TEMPLATE<typename T>
    FUNCTION max(a: T, b: T) -> T:
        RETURN (a > b) ? a : b
    
    // Works for int, double, string, custom types!
```

### 2. Function Template Syntax

**PSEUDOCODE:**
```
// Basic template function
TEMPLATE<typename T>
FUNCTION swap(a: T&, b: T&) -> void:
    DECLARE temp: T
    SET temp = a
    SET a = b
    SET b = temp

// Using the template
CALL swap(x: int, y: int)        // T becomes int
CALL swap(p: double, q: double)  // T becomes double
CALL swap(s1: string, s2: string) // T becomes string
```

**Compiler Process:**
1. See call to `swap(int, int)`
2. Generate specific version: `swap_int(int&, int&)`
3. See call to `swap(double, double)`
4. Generate specific version: `swap_double(double&, double&)`
5. Each generated at compile time!

### 3. Class Templates

**PSEUDOCODE Pattern:**
```
TEMPLATE<typename T>
CLASS ClassName:
    PRIVATE:
        T* data          // Can use T for member variables
        int size
    
    PUBLIC:
        CONSTRUCTOR ClassName(initialSize: int):
            SET size = initialSize
            ALLOCATE data = new array of T[size]
        
        FUNCTION get(index: int) -> T:
            RETURN data[index]
        
        FUNCTION set(index: int, value: T) -> void:
            SET data[index] = value
```

**Usage:**
```
CREATE object1: ClassName<int>(10)     // Template class of ints
CREATE object2: ClassName<double>(5)   // Template class of doubles
CREATE object3: ClassName<string>(20)  // Template class of strings
```

### 4. Multiple Template Parameters

**PSEUDOCODE:**
```
TEMPLATE<typename K, typename V>
CLASS Pair:
    PRIVATE:
        K key
        V value
    
    PUBLIC:
        CONSTRUCTOR Pair(k: K, v: V):
            SET key = k
            SET value = v
        
        FUNCTION getKey() -> K:
            RETURN key
        
        FUNCTION getValue() -> V:
            RETURN value

// Usage:
CREATE pair1: Pair<string, int>("age", 25)
CREATE pair2: Pair<int, double>(1, 3.14)
```

## 💡 Step-by-Step Example: Generic Stack

**Step 1: Identify What Should Be Generic**
- The data type stored in stack (int? double? string?)
- Stack operations (push, pop, peek) are same regardless of type

**Step 2: Design Template Structure**
```
PSEUDOCODE:

TEMPLATE<typename T>
CLASS Stack:
    PRIVATE:
        T* data          // Array of any type T
        int capacity
        int top_index
    
    PUBLIC:
        // Constructor
        CONSTRUCTOR Stack(cap: int = 100):
            IF cap <= 0:
                SET capacity = 100  // Default
            ELSE:
                SET capacity = cap
            
            ALLOCATE data = new array of T[capacity]
            SET top_index = -1  // Empty stack
        
        // Destructor
        DESTRUCTOR ~Stack():
            IF data != NULL:
                DELETE[] data
                SET data = NULL
        
        // Check if empty
        FUNCTION isEmpty() -> bool:
            RETURN top_index == -1
        
        // Check if full
        FUNCTION isFull() -> bool:
            RETURN top_index == capacity - 1
        
        // Push element
        FUNCTION push(item: T) -> bool:
            IF isFull():
                RETURN false  // Or resize
            
            INCREMENT top_index
            SET data[top_index] = item
            RETURN true
        
        // Pop element
        FUNCTION pop() -> T:
            IF isEmpty():
                THROW exception "Stack empty"
            
            DECLARE item: T = data[top_index]
            DECREMENT top_index
            RETURN item
        
        // Peek at top
        FUNCTION peek() -> T:
            IF isEmpty():
                THROW exception "Stack empty"
            
            RETURN data[top_index]
        
        // Get size
        FUNCTION size() -> int:
            RETURN top_index + 1
```

**Step 3: Consider Type Requirements**
For T to work with this stack, it must:
- Be copyable (for assignment `data[i] = item`)
- Have default constructor (for `new T[capacity]`)
- Be comparable if we add comparison operations

**Step 4: Edge Cases**
- Empty stack → pop/peek should handle
- Full stack → push should handle
- Stack of size 0?
- Stack of complex objects with dynamic memory?

**Step 5: Usage Examples (YOUR TURN to implement!)**
```
// Stack of integers
Stack<int> intStack(50)
intStack.push(10)
intStack.push(20)

// Stack of strings
Stack<string> stringStack(100)
stringStack.push("Hello")
stringStack.push("World")

// Stack of custom objects
Stack<Student> studentStack(30)
studentStack.push(Student("Alice", 123))
```

## 🧪 Testing Ideas

**Template Function Tests:**
```
1. Basic Type Test:
   - Call max<int>(5, 3) → returns 5
   - Call max<double>(2.5, 7.8) → returns 7.8
   - Call max<char>('a', 'z') → returns 'z'

2. String Test:
   - Call max<string>("apple", "banana")
   - Verify string comparison works

3. Custom Type Test:
   - Create custom class with operator>
   - Call template function with custom objects
   - Verify it compiles and works

4. Edge Cases:
   - max(x, x) → returns x (equal values)
   - swap with same variable?
```

**Template Class Tests:**
```
1. Basic Operations:
   - Create Stack<int>
   - Push several values
   - Pop and verify LIFO order
   - Verify size() correct

2. Different Types:
   - Test with int, double, string, custom class
   - Each should work independently

3. Empty Stack:
   - Create empty stack
   - Try pop → should handle gracefully
   - Try peek → should handle gracefully

4. Full Stack:
   - Fill stack to capacity
   - Try push → should return false or resize

5. Copy Operations:
   - If Big Three implemented
   - Test copy constructor
   - Test assignment operator
   - Verify deep copy works

6. Complex Objects:
   - Stack<vector<int>>
   - Stack of objects with pointers
   - Verify proper copying/destruction
```

## 📊 Complexity Analysis

**Template Overhead:**
- Compile time: Increases (must generate code for each type)
- Runtime: O(0) - NO overhead! Templates resolved at compile time
- Code size: Larger (separate code for each instantiated type)

**Template vs. Alternatives:**
```
Templates:
- Compile time: Higher
- Runtime: No overhead
- Type safety: Yes (compile-time checking)

Function Pointers/void*:
- Compile time: Lower  
- Runtime: Overhead from casting
- Type safety: No (runtime errors possible)

Inheritance/Polymorphism:
- Compile time: Lower
- Runtime: Virtual function overhead
- Type safety: Yes, but runtime binding
```

**Example: Stack Operations**
- push(): O(1) regardless of type
- pop(): O(1) regardless of type
- peek(): O(1) regardless of type

## 🎯 Practice Exercises

**Exercise 1: Generic Min Function**
Write template function to find minimum of two values.

Consider:
- Works with int, double, char?
- Works with strings?
- What if types can't be compared?
- How to handle custom types?

**Exercise 2: Generic Array Class**
Create template class for dynamic array:
- Add, remove, get operations
- Automatic resizing
- Works with any type T

Edge cases:
- Empty array?
- Array of pointers?
- Array of objects with dynamic memory?

**Exercise 3: Generic Pair/Tuple**
Template class storing two values of potentially different types:
- Store key-value pairs
- Getters for both values
- Comparison operators

Consider:
- Both types same vs. different?
- How to compare pairs?
- Copy semantics if types have pointers?

**Exercise 4: Generic Find Function**
Template function to find element in array:
```
TEMPLATE<typename T>
FUNCTION find(array: T[], size: int, target: T) -> int:
    // Return index of target, or -1 if not found
```

Questions:
- What operations needed on T?
- How to handle not found?
- What about efficiency?

## 🔧 Template Specialization (Advanced)

**Concept:** Provide specific implementation for certain types.

**PSEUDOCODE:**
```
// General template
TEMPLATE<typename T>
FUNCTION print(value: T) -> void:
    OUTPUT value

// Specialization for char*
TEMPLATE<>  // Note: empty angle brackets
FUNCTION print(value: char*) -> void:
    OUTPUT "String: " + value
```

**When to Use:**
- Specific type needs different implementation
- Optimization for particular types
- Handle special cases (e.g., char* vs. other pointers)

## ⚠️ Common Pitfalls

### 1. Template Definition Must Be Visible
```
BAD:
    // header.h
    template<typename T>
    class MyClass { ... };
    
    // implementation.cpp
    template<typename T>
    void MyClass<T>::function() { ... }
    
    // main.cpp
    #include "header.h"
    MyClass<int> obj;  // ERROR! Can't see implementation

GOOD:
    // header.h
    template<typename T>
    class MyClass {
        void function() { ... }  // Implement in header
    };
```

### 2. Type Requirements Not Met
```
BAD:
    TEMPLATE<typename T>
    FUNCTION max(a: T, b: T) -> T:
        RETURN (a > b) ? a : b
    
    CLASS NoComparison { ... };  // No operator>
    CALL max(obj1, obj2)  // COMPILE ERROR!

GOOD:
    Ensure T has operator> before using max
    Or provide operator> for your class
```

### 3. Ambiguous Template Calls
```
BAD:
    max(5, 3.14)  // int and double - which T?

GOOD:
    max<double>(5, 3.14)  // Explicit type
    max(5.0, 3.14)  // Both same type
```

## 🔑 Key Takeaways

1. **Templates = Code Reuse** - Write once, use with many types
2. **Compile-Time Magic** - No runtime overhead
3. **Type Safe** - Errors caught at compile time
4. **Put in Headers** - Template definitions must be visible
5. **Consider Requirements** - What operations must T support?
6. **Test Multiple Types** - Test with primitives, strings, custom classes
7. **Document Constraints** - Tell users what T must provide

## 🚀 Implementation Challenge

Implement the generic Stack class in C++:
1. Create template class in .h file
2. Implement all operations
3. Add copy constructor and assignment operator
4. Test with: int, double, string, custom class
5. Verify no memory leaks
6. Add resize functionality (bonus)

**Advanced Challenge:** Create a generic LinkedList template class!

## 📚 Related Topics
- Previous: [Dynamic Memory](02-dynamic-memory.md) - needed for template classes
- Next: [Linked Lists](04-linked-lists.md) - often implemented as templates
- See also: [Stacks](05-stacks.md) and [Queues](06-queues.md) - perfect for templates

---
**Remember:** Templates are powerful but must be designed carefully. Think about what operations your type parameter needs!
