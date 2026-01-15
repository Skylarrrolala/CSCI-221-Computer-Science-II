# Stacks

## 📖 Conceptual Overview

**What is a Stack?**
A Last-In-First-Out (LIFO) data structure. Think of a stack of plates: you add to the top and remove from the top.

**Real-World Analogies:**
- Stack of books
- Browser back button (last visited page first)
- Undo functionality in editors
- Function call stack in programming

**Key Operations:**
- **Push**: Add element to top
- **Pop**: Remove element from top
- **Peek/Top**: View top element without removing
- **isEmpty**: Check if stack is empty

## 🎯 Core Concepts

### 1. Stack ADT (Abstract Data Type)

**PSEUDOCODE Interface:**
```
ABSTRACT DATA TYPE Stack:
    OPERATIONS:
        push(element) -> void       // Add to top
        pop() -> element            // Remove and return top
        peek() -> element           // Return top without removing
        isEmpty() -> bool           // Check if empty
        isFull() -> bool            // Check if full (array-based)
        size() -> int               // Number of elements
        clear() -> void             // Remove all elements
```

### 2. Array-Based Implementation

**PSEUDOCODE:**
```
CLASS Stack:
    PRIVATE:
        dataType* data      // Dynamic array
        int capacity        // Maximum size
        int topIndex        // Index of top element (-1 if empty)
    
    PUBLIC:
        CONSTRUCTOR Stack(cap: int = 100):
            SET capacity = cap
            ALLOCATE data = new array of dataType[capacity]
            SET topIndex = -1  // Empty stack
        
        DESTRUCTOR ~Stack():
            DELETE[] data
        
        FUNCTION isEmpty() -> bool:
            RETURN topIndex == -1
        
        FUNCTION isFull() -> bool:
            RETURN topIndex == capacity - 1
        
        FUNCTION push(element: dataType) -> bool:
            // Check if full
            IF isFull():
                RETURN false  // Or resize
            
            // Increment top and add element
            INCREMENT topIndex
            SET data[topIndex] = element
            RETURN true
        
        FUNCTION pop() -> dataType:
            // Check if empty
            IF isEmpty():
                THROW exception "Stack underflow"
            
            // Get top element and decrement
            DECLARE element = data[topIndex]
            DECREMENT topIndex
            RETURN element
        
        FUNCTION peek() -> dataType:
            IF isEmpty():
                THROW exception "Stack empty"
            
            RETURN data[topIndex]
        
        FUNCTION size() -> int:
            RETURN topIndex + 1

COMPLEXITY:
- push(): O(1)
- pop(): O(1)
- peek(): O(1)
- isEmpty/isFull: O(1)
```

### 3. Linked List-Based Implementation

**PSEUDOCODE:**
```
STRUCTURE Node:
    dataType data
    Node* next

CLASS Stack:
    PRIVATE:
        Node* top      // Pointer to top node
        int count      // Number of elements
    
    PUBLIC:
        CONSTRUCTOR Stack():
            SET top = NULL
            SET count = 0
        
        DESTRUCTOR ~Stack():
            WHILE NOT isEmpty():
                CALL pop()
        
        FUNCTION isEmpty() -> bool:
            RETURN top == NULL
        
        FUNCTION push(element: dataType) -> void:
            // Create new node
            CREATE newNode with element
            
            // Link to current top
            SET newNode->next = top
            
            // Update top
            SET top = newNode
            INCREMENT count
        
        FUNCTION pop() -> dataType:
            IF isEmpty():
                THROW exception "Stack underflow"
            
            // Save top data
            DECLARE element = top->data
            
            // Save top node to delete
            DECLARE temp = top
            
            // Move top to next
            SET top = top->next
            
            // Delete old top
            DELETE temp
            DECREMENT count
            
            RETURN element
        
        FUNCTION peek() -> dataType:
            IF isEmpty():
                THROW exception "Stack empty"
            
            RETURN top->data
        
        FUNCTION size() -> int:
            RETURN count

ADVANTAGES:
- No fixed capacity (dynamic)
- No need to resize

DISADVANTAGES:
- Extra memory for pointers
- Slightly slower (pointer dereferencing)
```

## 💡 Step-by-Step Example: Expression Evaluation

**Problem: Check if parentheses are balanced**

```
Input: "( ( ) { [ ] } )"  → Balanced
Input: "( [ ) ]"          → Not balanced
```

**PSEUDOCODE Solution:**
```
FUNCTION isBalanced(expression: string) -> bool:
    CREATE stack: Stack<char>
    
    FOR each character in expression:
        IF character is opening bracket '(', '{', '[':
            PUSH character onto stack
        
        ELSE IF character is closing bracket ')', '}', ']':
            IF stack is empty:
                RETURN false  // No matching opening
            
            DECLARE top = stack.pop()
            
            // Check if matches
            IF character is ')' AND top is NOT '(':
                RETURN false
            IF character is '}' AND top is NOT '{':
                RETURN false
            IF character is ']' AND top is NOT '[':
                RETURN false
    
    // All brackets should be matched
    RETURN stack.isEmpty()

STEP-BY-STEP for "( [ ] )":
    1. See '(' → Push '(' → Stack: ['(']
    2. See '[' → Push '[' → Stack: ['(', '[']
    3. See ']' → Pop '[', matches → Stack: ['(']
    4. See ')' → Pop '(', matches → Stack: []
    5. End: Stack empty → BALANCED ✓

STEP-BY-STEP for "( [ ) ]":
    1. See '(' → Push '(' → Stack: ['(']
    2. See '[' → Push '[' → Stack: ['(', '[']
    3. See ')' → Pop '[', NO MATCH (expect ']') → NOT BALANCED ✗
```

## 🧪 Testing Ideas

**Basic Operations:**
```
1. Empty Stack Tests:
   - Create empty stack
   - isEmpty() → should return true
   - pop() → should throw exception
   - peek() → should throw exception
   - size() → should return 0

2. Single Element Tests:
   - Push one element
   - peek() → should return that element
   - Stack not empty
   - size() → should return 1
   - pop() → should return element
   - Stack should be empty after

3. Multiple Elements (LIFO):
   - Push 10, 20, 30
   - peek() → should return 30
   - pop() → should return 30
   - pop() → should return 20
   - pop() → should return 10
   - Verify LIFO order maintained

4. Full Stack (Array-Based):
   - Create stack with capacity 5
   - Push 5 elements
   - isFull() → should return true
   - push() → should fail or resize
   - pop() one
   - isFull() → should return false

5. Alternating Operations:
   - push, push, pop, push, pop, pop
   - Verify correct elements at each step
```

**Application Tests:**
```
6. Balanced Brackets:
   - "()" → balanced
   - "((()))" → balanced
   - "({[]})" → balanced
   - "(()" → not balanced
   - "([)]" → not balanced
   - "" → balanced (empty)

7. Expression Evaluation:
   - "3 4 + 5 *" (postfix) → 35
   - Test with various operators

8. Browser History:
   - Visit page 1, 2, 3
   - Back → should go to 2
   - Back → should go to 1
   - Back → should stay at 1 (no previous)
```

## 📊 Complexity Analysis

**Array-Based Stack:**
| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| push() | O(1) | - | Direct array access |
| pop() | O(1) | - | Direct array access |
| peek() | O(1) | - | Direct array access |
| isEmpty() | O(1) | - | Simple check |
| Overall Space | - | O(n) | Array of capacity n |

**Linked List-Based Stack:**
| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| push() | O(1) | O(1) | Add to front |
| pop() | O(1) | - | Remove from front |
| peek() | O(1) | - | Access first node |
| isEmpty() | O(1) | - | Check if top == NULL |
| Overall Space | - | O(n) | n nodes + n pointers |

**Application Complexities:**
- Balanced brackets: O(n) time, O(n) space (worst case all opening)
- Postfix evaluation: O(n) time, O(n) space
- Undo operations: O(1) per undo, O(k) space for k actions

## 🎯 Practice Exercises

**Exercise 1: Reverse String**
Use stack to reverse a string.

```
PSEUDOCODE:
FUNCTION reverseString(str: string) -> string:
    CREATE stack
    
    // Push all characters
    FOR each character in str:
        PUSH character
    
    // Pop to create reversed string
    CREATE result = ""
    WHILE NOT stack.isEmpty():
        result += stack.pop()
    
    RETURN result
```

Your task: Implement and test!

**Exercise 2: Postfix Evaluation**
Evaluate postfix expressions (e.g., "3 4 + 5 *" = 35).

Algorithm:
1. For each token:
   - If number: push to stack
   - If operator: pop two operands, apply operator, push result
2. Final result is top of stack

**Exercise 3: Infix to Postfix**
Convert "3 + 4 * 5" to "3 4 5 * +"

Use operator precedence and stack.

**Exercise 4: Min Stack**
Design stack that supports getMin() in O(1).

Hint: Use auxiliary stack to track minimums.

**Exercise 5: Valid Parentheses**
Implement the balanced brackets checker.

Edge cases:
- Empty string
- Only opening brackets
- Only closing brackets
- Mixed bracket types

**Exercise 6: Stack with Array Resizing**
Implement array-based stack that:
- Doubles capacity when full
- Shrinks when 1/4 full (to prevent thrashing)

## ⚠️ Common Pitfalls

### 1. Stack Underflow
```
BAD:
    pop() without checking isEmpty()
    → Runtime error or garbage value

GOOD:
    IF NOT isEmpty():
        value = pop()
    ELSE:
        Handle error appropriately
```

### 2. Stack Overflow (Array-Based)
```
BAD:
    push() when full
    → Array out of bounds

GOOD:
    IF NOT isFull():
        push(value)
    ELSE:
        Resize or return error
```

### 3. Memory Leaks (Linked List)
```
BAD:
    top = newNode  // Lost reference to old nodes!

GOOD:
    Properly implement destructor to delete all nodes
```

### 4. Off-by-One Errors
```
BAD:
    topIndex = 0 for empty  // Should be -1!

GOOD:
    topIndex = -1 for empty
    topIndex = 0 for first element
```

## 🔑 Key Takeaways

1. **LIFO Principle** - Last In, First Out
2. **Two Implementations** - Array (fixed/resizable) or Linked List
3. **O(1) Operations** - All operations constant time
4. **Check Empty** - Always check before pop/peek
5. **Real Applications** - Undo, expression parsing, function calls
6. **Choose Wisely** - Array for known bounds, List for dynamic

## 🚀 Implementation Challenge

**Level 1: Basic Stack**
1. Implement Stack class (choose array or linked list)
2. All standard operations
3. Comprehensive tests
4. No memory leaks

**Level 2: Applications**
1. Balanced brackets checker
2. String reversal
3. Postfix evaluator

**Level 3: Advanced**
1. Resizable array-based stack
2. Min stack with O(1) getMin()
3. Stack-based calculator with precedence

**Template Version:**
```cpp
template<typename T>
class Stack { ... }

// Test with different types
Stack<int> intStack;
Stack<string> stringStack;
Stack<CustomClass> objStack;
```

## 📚 Related Topics
- Previous: [Linked Lists](04-linked-lists.md) - for linked list implementation
- Next: [Queues](06-queues.md) - another fundamental ADT
- See also: [Recursion](07-recursion.md) - uses call stack
- Related: [Templates](03-templates.md) - for generic stack

---
**Remember:** When in doubt, draw the stack state at each step. Visualization prevents bugs!
