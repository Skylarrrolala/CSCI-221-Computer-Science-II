# Problem Set 4: Linked Lists

## Problem 1: Basic Singly Linked List 🟢 Easy

**Description:**
Implement a singly linked list from scratch with fundamental operations.

**Requirements:**

```
STRUCTURE Node:
    int data
    Node* next

CLASS LinkedList:
    PRIVATE:
        Node* head
        int size
    
    PUBLIC:
        // Core operations
        insertAtFront(value)
        insertAtEnd(value)
        deleteFromFront()
        search(value) -> bool
        display()
        getSize() -> int
        clear()
```

**Example Usage:**
```cpp
LinkedList list;
list.insertAtEnd(10);
list.insertAtEnd(20);
list.insertAtFront(5);
list.display();  // Output: 5 -> 10 -> 20 -> NULL

if (list.search(10)) {
    cout << "Found 10!" << endl;
}

list.deleteFromFront();
list.display();  // Output: 10 -> 20 -> NULL
```

**Edge Cases:**
- Delete from empty list?
- Search in empty list?
- Insert into empty list?
- Delete until list is empty?

**Test Ideas:**
1. Create empty list, verify size = 0
2. Insert at front, verify order
3. Insert at end, verify order
4. Mix inserts at front and end
5. Delete from front repeatedly until empty
6. Search for existing and non-existing values
7. Display empty list
8. Clear list, verify empty

**Complexity:**
- insertAtFront: O(1)
- insertAtEnd: O(n) without tail pointer
- deleteFromFront: O(1)
- search: O(n)
- display: O(n)

**Memory:** Don't forget destructor to avoid memory leaks!

**YOUR TASK:** Implement and test thoroughly!

---

## Problem 2: List with Insert at Position 🟡 Medium

**Description:**
Extend basic linked list to support insertion and deletion at any position.

**Additional Requirements:**
```
insertAtPosition(value, position) -> bool
deleteAtPosition(position) -> bool
getValueAt(position) -> int  // Returns value at position
```

**Example Usage:**
```cpp
LinkedList list;
list.insertAtEnd(10);
list.insertAtEnd(20);
list.insertAtEnd(40);
list.display();  // 10 -> 20 -> 40 -> NULL

list.insertAtPosition(30, 2);  // Insert 30 at index 2
list.display();  // 10 -> 20 -> 30 -> 40 -> NULL

list.deleteAtPosition(1);
list.display();  // 10 -> 30 -> 40 -> NULL

cout << list.getValueAt(1) << endl;  // 30
```

**Position Convention:** 0-indexed (0 is first element)

**Edge Cases:**
- Insert at position 0 (should work like insertAtFront)
- Insert at position = size (should work like insertAtEnd)
- Insert at position > size (invalid)
- Delete at invalid position
- Get value at invalid position

**Error Handling:**
- Return false for invalid positions in insert/delete
- Throw exception or return -1 for invalid getValueAt

**Test Ideas:**
1. Insert at position 0
2. Insert at middle position
3. Insert at position = size (end)
4. Insert at invalid position (negative, > size)
5. Delete at each valid position
6. Delete at invalid position
7. Get values at all positions
8. Mix operations

**Complexity:**
- insertAtPosition: O(n) - must traverse to position
- deleteAtPosition: O(n)
- getValueAt: O(n)

**YOUR TASK:** Add these operations to your LinkedList class!

---

## Problem 3: Reverse a Linked List 🟡 Medium

**Description:**
Add a method to reverse the linked list in-place.

**Requirements:**
```
reverse() -> void  // Reverses the list in-place
```

**Example:**
```cpp
LinkedList list;
list.insertAtEnd(1);
list.insertAtEnd(2);
list.insertAtEnd(3);
list.insertAtEnd(4);
list.display();  // 1 -> 2 -> 3 -> 4 -> NULL

list.reverse();
list.display();  // 4 -> 3 -> 2 -> 1 -> NULL
```

**Algorithm Hint:**
```
PSEUDOCODE for reverse():
    SET prev = NULL
    SET current = head
    
    WHILE current is not NULL:
        SET next = current->next     // Save next node
        SET current->next = prev     // Reverse the link
        SET prev = current           // Move prev forward
        SET current = next           // Move current forward
    
    SET head = prev                  // Update head
```

**Visualization:**
```
Before: 1 -> 2 -> 3 -> NULL

Step 1: NULL <- 1    2 -> 3 -> NULL
         prev  curr  next

Step 2: NULL <- 1 <- 2    3 -> NULL
                prev curr next

Step 3: NULL <- 1 <- 2 <- 3
                     prev curr(NULL)

After: 3 -> 2 -> 1 -> NULL
```

**Edge Cases:**
- Empty list
- Single node list
- Two node list
- Reverse twice (should get original)

**Test Ideas:**
1. Reverse empty list (should handle gracefully)
2. Reverse single node (should remain same)
3. Reverse multiple nodes, verify order
4. Reverse twice, verify back to original
5. Insert after reverse (should work normally)

**Complexity:**
- Time: O(n) - visit each node once
- Space: O(1) - only a few pointers

**Challenge:** Can you implement recursively?

**YOUR TASK:** Implement the reverse method!

---

## Problem 4: Detect Cycle in Linked List 🔴 Hard

**Description:**
Detect if linked list has a cycle (a node points back to a previous node).

**Requirements:**
```
hasCycle() -> bool  // Returns true if cycle exists
```

**Example of Cycle:**
```
1 -> 2 -> 3 -> 4
     ^         |
     |_________|

Node 4 points back to node 2, creating a cycle.
```

**Algorithm: Floyd's Cycle Detection (Tortoise and Hare)**
```
PSEUDOCODE:
    IF head is NULL OR head->next is NULL:
        RETURN false  // No cycle possible
    
    SET slow = head       // Moves 1 step at a time
    SET fast = head       // Moves 2 steps at a time
    
    WHILE fast is not NULL AND fast->next is not NULL:
        SET slow = slow->next
        SET fast = fast->next->next
        
        IF slow == fast:
            RETURN true   // Cycle detected!
    
    RETURN false          // No cycle
```

**Why This Works:**
- If there's a cycle, fast pointer will eventually catch up to slow pointer
- Like two runners on a circular track - faster one laps slower one
- If no cycle, fast pointer reaches NULL

**Testing Cycle Detection:**
Since your class should not normally have cycles, you'll need to create them manually for testing:

```cpp
// Create a cycle for testing (ONLY for testing!)
Node* temp = list.head;
while (temp->next != NULL) {
    temp = temp->next;  // Go to last node
}
temp->next = list.head->next;  // Create cycle to 2nd node

if (list.hasCycle()) {
    cout << "Cycle detected!" << endl;
}
```

**Edge Cases:**
- Empty list (no cycle)
- Single node pointing to itself
- Single node pointing to NULL (no cycle)
- Cycle at beginning (last -> first)
- Cycle in middle
- No cycle

**Test Ideas:**
1. Empty list → false
2. Single node, no cycle → false
3. Multiple nodes, no cycle → false
4. Create cycle to first node → true
5. Create cycle to middle node → true
6. Create self-loop (node->next = itself) → true

**Complexity:**
- Time: O(n) - at most 2n iterations
- Space: O(1) - only two pointers

**Important:** After testing, break the cycle! Otherwise you can't delete the list properly.

**Bonus Challenge:** If cycle exists, find where it starts!

**YOUR TASK:** Implement cycle detection!

---

## Problem 5: Merge Two Sorted Lists 🔴 Hard

**Description:**
Merge two sorted linked lists into one sorted list.

**Requirements:**
```
merge(otherList) -> LinkedList  // Returns new merged sorted list
// Or: static method
static merge(list1, list2) -> LinkedList
```

**Example:**
```cpp
LinkedList list1;
list1.insertAtEnd(1);
list1.insertAtEnd(3);
list1.insertAtEnd(5);

LinkedList list2;
list2.insertAtEnd(2);
list2.insertAtEnd(4);
list2.insertAtEnd(6);

LinkedList merged = LinkedList::merge(list1, list2);
merged.display();  // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
```

**Algorithm:**
```
PSEUDOCODE:
    CREATE newList
    SET ptr1 = list1.head
    SET ptr2 = list2.head
    
    WHILE ptr1 is not NULL AND ptr2 is not NULL:
        IF ptr1->data <= ptr2->data:
            newList.insertAtEnd(ptr1->data)
            ptr1 = ptr1->next
        ELSE:
            newList.insertAtEnd(ptr2->data)
            ptr2 = ptr2->next
    
    // Add remaining elements from list1
    WHILE ptr1 is not NULL:
        newList.insertAtEnd(ptr1->data)
        ptr1 = ptr1->next
    
    // Add remaining elements from list2
    WHILE ptr2 is not NULL:
        newList.insertAtEnd(ptr2->data)
        ptr2 = ptr2->next
    
    RETURN newList
```

**Edge Cases:**
- One or both lists empty
- Lists of different lengths
- One list exhausted before other
- All elements of list1 < all elements of list2
- Lists with duplicate values

**Test Ideas:**
1. Merge two empty lists
2. Merge empty with non-empty
3. Merge lists of equal length
4. Merge lists of different lengths
5. Merge with duplicates
6. Merge where all list1 < all list2
7. Merge where lists are interlaced

**Complexity:**
- Time: O(n + m) where n, m are list lengths
- Space: O(n + m) for new list

**Bonus Challenge:** Can you merge in-place without creating new list?

**YOUR TASK:** Implement merge operation!

---

## Evaluation Criteria

Your linked list implementation should:
1. ✅ Have no memory leaks (destructor properly deletes all nodes)
2. ✅ Handle all edge cases (empty list, single node, etc.)
3. ✅ Use proper pointer manipulation
4. ✅ Implement Big Three if needed (copy constructor, assignment)
5. ✅ Have clear, commented code
6. ✅ Include comprehensive tests

## 🎯 Testing Strategy

Create a test driver that:
- Tests each operation individually
- Tests edge cases explicitly
- Verifies list state after each operation
- Checks for memory leaks with valgrind
- Displays results clearly

## 🚀 Next Steps

After mastering linked lists:
1. Implement doubly linked list
2. Implement circular linked list
3. Use linked list to implement Stack
4. Use linked list to implement Queue
5. Move to Problem Set 5 (Stacks)!

---
**Remember:** Draw diagrams! Linked list bugs are often pointer errors that are obvious when visualized. Always trace through with a picture!
