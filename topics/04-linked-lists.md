# Linked Lists

## 📖 Conceptual Overview

**What is a Linked List?**
A dynamic data structure where elements (nodes) are connected via pointers. Each node contains data and a pointer to the next node.

**Why Use Linked Lists?**
- Dynamic size (grows/shrinks easily)
- Efficient insertion/deletion (no shifting like arrays)
- No wasted memory from pre-allocation
- Foundation for other structures (stacks, queues)

**Trade-off:** Slower access (must traverse from head) vs. arrays (direct index access)

## 🎯 Core Concepts

### 1. Node Structure

**PSEUDOCODE:**
```
STRUCTURE Node:
    DATA:
        dataType data      // The actual data stored
        Node* next         // Pointer to next node
    
    CONSTRUCTOR Node(value: dataType):
        SET data = value
        SET next = NULL    // Initially points nowhere
```

**Visualization:**
```
    [data|next] -> [data|next] -> [data|next] -> NULL
     Node 1         Node 2         Node 3
```

### 2. Singly Linked List Class

**PSEUDOCODE Structure:**
```
CLASS LinkedList:
    PRIVATE:
        Node* head         // Pointer to first node
        int size           // Number of nodes
    
    PUBLIC:
        CONSTRUCTOR LinkedList():
            SET head = NULL
            SET size = 0
        
        DESTRUCTOR ~LinkedList():
            CALL clear()   // Delete all nodes
        
        // Core operations
        FUNCTION insertAtFront(value)
        FUNCTION insertAtEnd(value)
        FUNCTION insertAtPosition(value, position)
        FUNCTION deleteFromFront()
        FUNCTION deleteFromEnd()
        FUNCTION deleteValue(value)
        FUNCTION search(value) -> bool
        FUNCTION display()
        FUNCTION clear()
```

### 3. Insert Operations

**Insert at Front (Head):**
```
PSEUDOCODE:

FUNCTION insertAtFront(value) -> void:
    // Step 1: Create new node
    CREATE newNode with value
    
    // Step 2: Point new node to current head
    SET newNode->next = head
    
    // Step 3: Update head to new node
    SET head = newNode
    
    // Step 4: Increment size
    INCREMENT size

COMPLEXITY: O(1) - constant time, no traversal needed
```

**Insert at End (Tail):**
```
PSEUDOCODE:

FUNCTION insertAtEnd(value) -> void:
    // Step 1: Create new node
    CREATE newNode with value
    SET newNode->next = NULL
    
    // Step 2: Handle empty list
    IF head == NULL:
        SET head = newNode
        INCREMENT size
        RETURN
    
    // Step 3: Traverse to last node
    SET current = head
    WHILE current->next != NULL:
        SET current = current->next
    
    // Step 4: Link last node to new node
    SET current->next = newNode
    INCREMENT size

COMPLEXITY: O(n) - must traverse entire list
```

**Insert at Position:**
```
PSEUDOCODE:

FUNCTION insertAtPosition(value, position) -> bool:
    // Edge case: invalid position
    IF position < 0 OR position > size:
        RETURN false
    
    // Special case: insert at front
    IF position == 0:
        CALL insertAtFront(value)
        RETURN true
    
    // Create new node
    CREATE newNode with value
    
    // Traverse to position-1
    SET current = head
    FOR i from 0 to position-2:
        SET current = current->next
    
    // Insert between current and current->next
    SET newNode->next = current->next
    SET current->next = newNode
    INCREMENT size
    RETURN true

COMPLEXITY: O(n) - may traverse up to n nodes
```

### 4. Delete Operations

**Delete from Front:**
```
PSEUDOCODE:

FUNCTION deleteFromFront() -> bool:
    // Edge case: empty list
    IF head == NULL:
        RETURN false
    
    // Save node to delete
    SET temp = head
    
    // Move head to next node
    SET head = head->next
    
    // Delete old head
    DELETE temp
    DECREMENT size
    RETURN true

COMPLEXITY: O(1) - constant time
```

**Delete from End:**
```
PSEUDOCODE:

FUNCTION deleteFromEnd() -> bool:
    // Edge case: empty list
    IF head == NULL:
        RETURN false
    
    // Special case: only one node
    IF head->next == NULL:
        DELETE head
        SET head = NULL
        DECREMENT size
        RETURN true
    
    // Traverse to second-to-last node
    SET current = head
    WHILE current->next->next != NULL:
        SET current = current->next
    
    // Delete last node
    DELETE current->next
    SET current->next = NULL
    DECREMENT size
    RETURN true

COMPLEXITY: O(n) - must traverse to end
```

**Delete Specific Value:**
```
PSEUDOCODE:

FUNCTION deleteValue(value) -> bool:
    // Edge case: empty list
    IF head == NULL:
        RETURN false
    
    // Special case: delete head
    IF head->data == value:
        SET temp = head
        SET head = head->next
        DELETE temp
        DECREMENT size
        RETURN true
    
    // Search for value
    SET current = head
    WHILE current->next != NULL:
        IF current->next->data == value:
            // Found it! Delete current->next
            SET temp = current->next
            SET current->next = temp->next
            DELETE temp
            DECREMENT size
            RETURN true
        SET current = current->next
    
    RETURN false  // Not found

COMPLEXITY: O(n) - may search entire list
```

### 5. Search and Display

**Search:**
```
PSEUDOCODE:

FUNCTION search(value) -> bool:
    SET current = head
    WHILE current != NULL:
        IF current->data == value:
            RETURN true
        SET current = current->next
    RETURN false

COMPLEXITY: O(n) - may search entire list
```

**Display:**
```
PSEUDOCODE:

FUNCTION display() -> void:
    IF head == NULL:
        OUTPUT "List is empty"
        RETURN
    
    SET current = head
    WHILE current != NULL:
        OUTPUT current->data
        IF current->next != NULL:
            OUTPUT " -> "
        SET current = current->next
    OUTPUT " -> NULL"

COMPLEXITY: O(n) - must visit all nodes
```

### 6. Cleanup (Destructor)

**Clear All Nodes:**
```
PSEUDOCODE:

FUNCTION clear() -> void:
    WHILE head != NULL:
        SET temp = head
        SET head = head->next
        DELETE temp
    SET size = 0

COMPLEXITY: O(n) - must delete all nodes
```

## 💡 Step-by-Step Example: Building a List

**Scenario: Create list [10, 20, 30, 40]**

```
Step 1: insertAtEnd(10)
    head -> [10|NULL]
    
Step 2: insertAtEnd(20)
    head -> [10|*] -> [20|NULL]
    
Step 3: insertAtEnd(30)
    head -> [10|*] -> [20|*] -> [30|NULL]
    
Step 4: insertAtEnd(40)
    head -> [10|*] -> [20|*] -> [30|*] -> [40|NULL]

Step 5: insertAtPosition(25, 2)
    head -> [10|*] -> [20|*] -> [25|*] -> [30|*] -> [40|NULL]

Step 6: deleteFromFront()
    head -> [20|*] -> [25|*] -> [30|*] -> [40|NULL]

Step 7: deleteValue(30)
    head -> [20|*] -> [25|*] -> [40|NULL]
```

## 🧪 Testing Ideas

**Basic Operations:**
```
1. Empty List Tests:
   - Create empty list
   - Try deleteFromFront → should fail gracefully
   - Try search → should return false
   - Display → should show "empty"

2. Single Node Tests:
   - Insert one node
   - Delete that node
   - Verify list empty after

3. Insert Tests:
   - insertAtFront multiple times → verify reverse order
   - insertAtEnd multiple times → verify correct order
   - insertAtPosition at 0, middle, end
   - insertAtPosition with invalid index

4. Delete Tests:
   - deleteFromFront until empty
   - deleteFromEnd until empty
   - deleteValue existing value
   - deleteValue non-existing value
   - Delete from single-node list

5. Search Tests:
   - Search in empty list
   - Search existing values
   - Search non-existing values
   - Search in single-node list

6. Edge Cases:
   - Very large list (1000+ nodes)
   - Insert/delete alternating
   - Multiple nodes with same value
```

**Memory Tests:**
```
7. Memory Leak Check:
   - Create list, add many nodes
   - Delete all via clear()
   - Run valgrind → should show no leaks

8. Destructor Test:
   - Create list in scope { }
   - Add nodes
   - Exit scope → destructor called
   - Verify no leaks
```

## 📊 Complexity Analysis

**Time Complexity Summary:**
| Operation | Average Case | Worst Case | Notes |
|-----------|-------------|------------|-------|
| insertAtFront | O(1) | O(1) | No traversal |
| insertAtEnd | O(n) | O(n) | Full traversal |
| insertAtPosition | O(n) | O(n) | Traverse to position |
| deleteFromFront | O(1) | O(1) | No traversal |
| deleteFromEnd | O(n) | O(n) | Find second-to-last |
| deleteValue | O(n) | O(n) | May search entire list |
| search | O(n) | O(n) | Linear search |

**Space Complexity:**
- O(n) where n = number of nodes
- Each node takes constant space
- No auxiliary space needed for operations

**Comparison with Arrays:**
```
Linked List:
- Insert/Delete at front: O(1) ✓
- Insert/Delete at end: O(n) (without tail pointer)
- Access by index: O(n) ✗
- Search: O(n)
- Dynamic size: Yes ✓

Array:
- Insert/Delete at front: O(n) (shifting)
- Insert/Delete at end: O(1) (if space available)
- Access by index: O(1) ✓
- Search: O(n) (or O(log n) if sorted)
- Dynamic size: No (or expensive resize)
```

## 🎯 Practice Exercises

**Exercise 1: Doubly Linked List**
Extend to doubly linked (prev and next pointers):
```
STRUCTURE Node:
    data
    Node* next
    Node* prev
```

Benefits:
- Traverse backwards
- Faster deleteFromEnd: O(1) with tail pointer

Edge cases:
- Updating both prev and next
- Handling head/tail specially

**Exercise 2: Circular Linked List**
Last node points back to head:
```
tail->next = head
```

Consider:
- How to detect end of traversal?
- How to prevent infinite loops?

**Exercise 3: Additional Operations**
Implement:
- `reverse()` - reverse the list in place
- `findMiddle()` - find middle node (fast/slow pointer)
- `hasCycle()` - detect if list has cycle
- `removeDuplicates()` - remove duplicate values
- `merge(otherList)` - merge two sorted lists

**Exercise 4: Template Version**
Convert to template class:
```
template<typename T>
class LinkedList { ... }
```

## ⚠️ Common Pitfalls

### 1. Memory Leaks
```
BAD:
    head = newNode  // Lost reference to old list!

GOOD:
    Clear old list first, then assign
```

### 2. Dangling Pointers
```
BAD:
    DELETE current
    current->next  // Accessing deleted memory!

GOOD:
    temp = current->next
    DELETE current
    current = temp
```

### 3. Null Pointer Dereferencing
```
BAD:
    current->next->data  // What if current->next is NULL?

GOOD:
    IF current != NULL AND current->next != NULL:
        USE current->next->data
```

### 4. Losing Head Pointer
```
BAD:
    WHILE head != NULL:  // Moving head itself!
        head = head->next

GOOD:
    current = head
    WHILE current != NULL:
        current = current->next
```

## 🔑 Key Takeaways

1. **Always check for NULL** before dereferencing
2. **Free memory** - delete all nodes in destructor
3. **Update size** - keep track of node count
4. **Handle edge cases** - empty list, single node
5. **Use temp pointers** - don't lose references
6. **Draw diagrams** - visualize pointer changes
7. **Test thoroughly** - especially boundary cases

## 🚀 Implementation Challenge

Implement a complete LinkedList class in C++:
1. Create Node structure and LinkedList class
2. Implement all insert/delete operations
3. Add copy constructor and assignment operator (deep copy!)
4. Test with comprehensive test cases
5. Verify no memory leaks with valgrind

**Bonus Challenges:**
- Add tail pointer for O(1) insertAtEnd
- Implement as template class
- Add iterator support

## 📚 Related Topics
- Previous: [Templates](03-templates.md) - for generic linked lists
- Next: [Stacks](05-stacks.md) - can be implemented with linked list
- See also: [Queues](06-queues.md) - also uses linked list
- Related: [Dynamic Memory](02-dynamic-memory.md) - essential for nodes

---
**Remember:** Draw it out! Linked list operations are much clearer with diagrams. Always visualize before coding!
