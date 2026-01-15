# Queues

## 📖 Conceptual Overview

**What is a Queue?**
A First-In-First-Out (FIFO) data structure. Think of a line at a store: first person in line is first to be served.

**Real-World Analogies:**
- Line at a ticket counter
- Print queue (documents wait their turn)
- Task scheduling in operating systems
- Breadth-first search in graphs
- Message queues in systems

**Key Operations:**
- **Enqueue**: Add element to back (rear)
- **Dequeue**: Remove element from front
- **Front/Peek**: View front element without removing
- **isEmpty**: Check if queue is empty

## 🎯 Core Concepts

### 1. Queue ADT (Abstract Data Type)

**PSEUDOCODE Interface:**
```
ABSTRACT DATA TYPE Queue:
    OPERATIONS:
        enqueue(element) -> void    // Add to rear
        dequeue() -> element        // Remove from front
        front() -> element          // View front without removing
        isEmpty() -> bool           // Check if empty
        isFull() -> bool           // Check if full (array-based)
        size() -> int              // Number of elements
        clear() -> void            // Remove all elements
```

### 2. Array-Based Implementation (Circular)

**Why Circular?**
Without circular: dequeue leaves empty space at front → wasted memory
With circular: wrap around to reuse space → efficient

**PSEUDOCODE:**
```
CLASS Queue:
    PRIVATE:
        dataType* data
        int capacity
        int frontIndex    // Index of front element
        int rearIndex     // Index where next element goes
        int count         // Number of elements
    
    PUBLIC:
        CONSTRUCTOR Queue(cap: int = 100):
            SET capacity = cap
            ALLOCATE data = new array[capacity]
            SET frontIndex = 0
            SET rearIndex = 0
            SET count = 0
        
        DESTRUCTOR ~Queue():
            DELETE[] data
        
        FUNCTION isEmpty() -> bool:
            RETURN count == 0
        
        FUNCTION isFull() -> bool:
            RETURN count == capacity
        
        FUNCTION enqueue(element: dataType) -> bool:
            IF isFull():
                RETURN false  // Or resize
            
            // Add at rear
            SET data[rearIndex] = element
            
            // Move rear circularly
            SET rearIndex = (rearIndex + 1) % capacity
            
            INCREMENT count
            RETURN true
        
        FUNCTION dequeue() -> dataType:
            IF isEmpty():
                THROW exception "Queue underflow"
            
            // Get front element
            DECLARE element = data[frontIndex]
            
            // Move front circularly
            SET frontIndex = (frontIndex + 1) % capacity
            
            DECREMENT count
            RETURN element
        
        FUNCTION front() -> dataType:
            IF isEmpty():
                THROW exception "Queue empty"
            
            RETURN data[frontIndex]
        
        FUNCTION size() -> int:
            RETURN count

COMPLEXITY:
- enqueue(): O(1)
- dequeue(): O(1)
- front(): O(1)
- isEmpty/isFull: O(1)
```

**Circular Array Visualization:**
```
Initial: capacity=5, front=0, rear=0, count=0
[_][_][_][_][_]
 ^
 front, rear

After enqueue(10,20,30):
[10][20][30][_][_]
 ^          ^
 front      rear, count=3

After dequeue() twice:
[10][20][30][_][_]
         ^   ^
         front  rear, count=1

After enqueue(40,50,60):
[50][60][30][40][_]
         ^       ^
         front   rear, count=4
         (wrapped around!)
```

### 3. Linked List-Based Implementation

**PSEUDOCODE:**
```
STRUCTURE Node:
    dataType data
    Node* next

CLASS Queue:
    PRIVATE:
        Node* front    // Pointer to front node
        Node* rear     // Pointer to rear node
        int count
    
    PUBLIC:
        CONSTRUCTOR Queue():
            SET front = NULL
            SET rear = NULL
            SET count = 0
        
        DESTRUCTOR ~Queue():
            WHILE NOT isEmpty():
                CALL dequeue()
        
        FUNCTION isEmpty() -> bool:
            RETURN front == NULL
        
        FUNCTION enqueue(element: dataType) -> void:
            // Create new node
            CREATE newNode with element
            SET newNode->next = NULL
            
            IF isEmpty():
                // First element
                SET front = newNode
                SET rear = newNode
            ELSE:
                // Add to rear
                SET rear->next = newNode
                SET rear = newNode
            
            INCREMENT count
        
        FUNCTION dequeue() -> dataType:
            IF isEmpty():
                THROW exception "Queue underflow"
            
            // Save front data
            DECLARE element = front->data
            
            // Save front node to delete
            DECLARE temp = front
            
            // Move front to next
            SET front = front->next
            
            // If queue becomes empty, update rear too
            IF front == NULL:
                SET rear = NULL
            
            DELETE temp
            DECREMENT count
            
            RETURN element
        
        FUNCTION front() -> dataType:
            IF isEmpty():
                THROW exception "Queue empty"
            
            RETURN front->data
        
        FUNCTION size() -> int:
            RETURN count

ADVANTAGES:
- No fixed capacity
- Simple implementation
- No circular index logic

DISADVANTAGES:
- Extra memory for pointers
- Dynamic allocation overhead
```

## 💡 Step-by-Step Example: Task Scheduler

**Problem: Simulate task processing**

```
PSEUDOCODE:

FUNCTION processTaskQueue():
    CREATE queue: Queue<string>
    
    // Add tasks
    queue.enqueue("Task 1: Read email")
    queue.enqueue("Task 2: Write report")
    queue.enqueue("Task 3: Meeting")
    queue.enqueue("Task 4: Code review")
    
    // Process tasks in order (FIFO)
    WHILE NOT queue.isEmpty():
        DECLARE currentTask = queue.dequeue()
        OUTPUT "Processing: " + currentTask
        // Simulate work
        WAIT 1 second

EXECUTION:
    Enqueue Task 1
    Enqueue Task 2
    Enqueue Task 3
    Enqueue Task 4
    
    Queue: [Task1, Task2, Task3, Task4]
            ^front              ^rear
    
    Dequeue → Process "Task 1"
    Queue: [Task2, Task3, Task4]
            ^front         ^rear
    
    Dequeue → Process "Task 2"
    Queue: [Task3, Task4]
            ^front    ^rear
    
    Dequeue → Process "Task 3"
    Queue: [Task4]
            ^front/rear
    
    Dequeue → Process "Task 4"
    Queue: [] (empty)
```

## 🧪 Testing Ideas

**Basic Operations:**
```
1. Empty Queue Tests:
   - Create empty queue
   - isEmpty() → should return true
   - dequeue() → should throw exception
   - front() → should throw exception
   - size() → should return 0

2. Single Element Tests:
   - Enqueue one element
   - front() → should return that element
   - Queue not empty
   - size() → should return 1
   - dequeue() → should return element
   - Queue empty after

3. Multiple Elements (FIFO):
   - Enqueue 10, 20, 30
   - front() → should return 10 (first in)
   - dequeue() → should return 10
   - dequeue() → should return 20
   - dequeue() → should return 30
   - Verify FIFO order maintained

4. Full Queue (Array-Based):
   - Create queue with capacity 5
   - Enqueue 5 elements
   - isFull() → should return true
   - enqueue() → should fail or resize
   - dequeue() one
   - isFull() → should return false

5. Circular Behavior (Array):
   - Fill queue to capacity
   - Dequeue several elements
   - Enqueue new elements
   - Verify wraparound works correctly
```

**Edge Cases:**
```
6. Alternating Operations:
   - enqueue, enqueue, dequeue, enqueue, dequeue
   - Verify correct elements at each step
   - Test with capacity exactly filled

7. Fill and Empty Repeatedly:
   - Fill queue completely
   - Empty it completely
   - Repeat several times
   - Check for memory leaks

8. Large Queue:
   - Enqueue 10,000 elements
   - Dequeue all
   - Verify performance and correctness
```

**Application Tests:**
```
9. Print Queue Simulation:
   - Add print jobs
   - Process in order
   - Verify FIFO processing

10. BFS Traversal:
    - Use queue for breadth-first search
    - Verify level-order traversal
```

## 📊 Complexity Analysis

**Array-Based Queue (Circular):**
| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| enqueue() | O(1) | - | Direct index calculation |
| dequeue() | O(1) | - | Direct index calculation |
| front() | O(1) | - | Direct access |
| isEmpty() | O(1) | - | Simple check |
| Overall Space | - | O(n) | Array of capacity n |

**Linked List-Based Queue:**
| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| enqueue() | O(1) | O(1) | Add to rear pointer |
| dequeue() | O(1) | - | Remove from front |
| front() | O(1) | - | Access front pointer |
| isEmpty() | O(1) | - | Check if front == NULL |
| Overall Space | - | O(n) | n nodes + pointers |

**Queue vs. Stack:**
```
Queue (FIFO):
- Order: First in, first out
- Use: Fair processing, level-order
- Access: Front and rear

Stack (LIFO):
- Order: Last in, first out
- Use: Reversal, backtracking
- Access: Top only
```

## 🎯 Practice Exercises

**Exercise 1: Hot Potato Game**
n people in circle, pass potato every k counts, eliminate holder.

```
PSEUDOCODE:
FUNCTION hotPotato(names: array, k: int) -> string:
    CREATE queue
    
    FOR each name in names:
        queue.enqueue(name)
    
    WHILE queue.size() > 1:
        // Pass potato k times
        FOR i from 1 to k-1:
            person = queue.dequeue()
            queue.enqueue(person)  // Move to back
        
        // Eliminate kth person
        eliminated = queue.dequeue()
        OUTPUT eliminated + " is out"
    
    RETURN queue.dequeue()  // Winner
```

Your task: Implement and test!

**Exercise 2: Palindrome Checker**
Use queue and stack together to check if string is palindrome.

Algorithm:
1. Push all characters to stack
2. Enqueue all characters to queue
3. Pop from stack and dequeue from queue
4. Compare - if all match, it's palindrome

**Exercise 3: Queue Reversal**
Reverse a queue using a stack.

Hint:
1. Dequeue all to stack
2. Pop all from stack back to queue

**Exercise 4: Circular Tour**
Given gas stations in circle, find starting point to complete circuit.

**Exercise 5: Queue Using Two Stacks**
Implement queue using only two stacks.

Challenge: Make one operation O(1) and other amortized O(1).

**Exercise 6: Priority Queue**
Extend queue to support priorities.

High priority elements dequeue first, even if not at front.

## ⚠️ Common Pitfalls

### 1. Forgetting Circular Logic (Array)
```
BAD:
    rearIndex = rearIndex + 1  // May exceed capacity!

GOOD:
    rearIndex = (rearIndex + 1) % capacity
```

### 2. Not Updating Rear on Last Dequeue
```
BAD (Linked List):
    front = front->next
    // rear still points to deleted node!

GOOD:
    front = front->next
    IF front == NULL:
        rear = NULL  // Queue is empty
```

### 3. Using Wrong Index
```
BAD:
    return data[rearIndex]  // Should be frontIndex!

GOOD:
    return data[frontIndex]
```

### 4. Queue Underflow
```
BAD:
    dequeue() without checking isEmpty()

GOOD:
    IF NOT isEmpty():
        value = dequeue()
    ELSE:
        Handle error
```

## 🔑 Key Takeaways

1. **FIFO Principle** - First In, First Out
2. **Circular Array** - Efficient space usage
3. **Front and Rear** - Track both ends
4. **O(1) Operations** - All operations constant time
5. **Fair Processing** - No element cut in line
6. **Two Implementations** - Array (circular) or Linked List
7. **Choose Based on Needs** - Fixed capacity vs. dynamic

## 🚀 Implementation Challenge

**Level 1: Basic Queue**
1. Implement Queue class (choose array or linked list)
2. All standard operations
3. Comprehensive tests including wraparound (if array)
4. No memory leaks

**Level 2: Applications**
1. Task scheduler simulation
2. Hot potato game
3. Palindrome checker with queue+stack

**Level 3: Advanced**
1. Resizable circular array queue
2. Priority queue
3. Queue using two stacks
4. Deque (double-ended queue)

**Template Version:**
```cpp
template<typename T>
class Queue { ... }

// Test with different types
Queue<int> intQueue;
Queue<string> taskQueue;
Queue<Request> requestQueue;
```

## 📚 Related Topics
- Previous: [Stacks](05-stacks.md) - complementary data structure
- Next: [Recursion](07-recursion.md) - uses queue in BFS
- See also: [Linked Lists](04-linked-lists.md) - for linked implementation
- Related: [Algorithm Analysis](08-algorithm-analysis.md) - queue complexities

## 🎓 Queue vs Stack Decision Guide

**Use Queue when:**
- Need fair, ordered processing (FIFO)
- Breadth-first traversal
- Task scheduling
- Buffer for data streams

**Use Stack when:**
- Need to reverse order (LIFO)
- Backtracking algorithms
- Depth-first traversal
- Expression evaluation

---
**Remember:** Queue = Line at a store. Fair and orderly. Draw the queue state to visualize operations!
