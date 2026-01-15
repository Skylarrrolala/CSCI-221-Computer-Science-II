# Chapter 13: Pointers and Linked Lists - Concept Notes

## What this chapter is about

Linked lists are dynamic data structures where each element (node) points to the next one in the chain. Unlike arrays, linked lists can easily grow and shrink, and you can insert or remove elements in the middle without shifting everything. Lab 13 involves reversing a linked list, and Quiz 5 tests your understanding of node structures, traversal, and pointer manipulation. This chapter builds heavily on your pointer knowledge from Chapter 9.

## Key ideas in plain words

- **A linked list is a chain of nodes** where each node contains data and a pointer to the next node.
- **A node is a struct** (or class) with at least two parts: the data and a pointer to the next node.
- **The head pointer** points to the first node in the list. If the list is empty, head is `nullptr`.
- **The last node's next pointer is `nullptr`** - this marks the end of the list.
- **Traversal means walking through the list** by following the next pointers from node to node.
- **Insertion can happen at the front, middle, or end** - adjust pointers to add a node.
- **Deletion requires updating pointers** to skip over the node, then freeing its memory.
- **Self-referential structures** are structs/classes that contain pointers to their own type.
- **Dynamic allocation is essential** - each node is created with `new` and destroyed with `delete`.
- **Losing a pointer to a node** means you can't reach the rest of the list (memory leak).

## Tiny C++ examples

### Example 1: Node structure definition
```cpp
struct Node {
    int data;
    Node* next;
};
```
**Explanation:** A simple node holds an integer and a pointer to the next Node. This is a self-referential structure because `next` points to another `Node`.

### Example 2: Creating a small linked list
```cpp
Node* head = new Node;
head->data = 10;
head->next = new Node;
head->next->data = 20;
head->next->next = new Node;
head->next->next->data = 30;
head->next->next->next = nullptr;  // end of list
```
**Explanation:** We create three nodes manually. The first node points to the second, which points to the third, which points to `nullptr` (end).

### Example 3: Traversing a linked list
```cpp
Node* current = head;
while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
}
cout << endl;  // prints: 10 20 30
```
**Explanation:** Start at `head` and follow the `next` pointers until you reach `nullptr`. This visits every node in order.

### Example 4: Inserting at the front
```cpp
void insertFront(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;  // new node points to old head
    head = newNode;        // head now points to new node
}
```
**Explanation:** Create a new node, make it point to the current head, then update head to point to the new node. This adds a node at the beginning.

### Example 5: Deleting the entire list
```cpp
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
```
**Explanation:** Move through the list, saving each node in `temp`, advancing `head`, then deleting `temp`. This frees all memory.

## How to build something small

Here's how to create a basic linked list of integers:

1. **Define the Node structure** - `struct Node { int data; Node* next; };`
2. **Initialize head pointer** - `Node* head = nullptr;` (empty list)
3. **Write a function to insert at front** - Create new node, set its next to head, update head
4. **Add several nodes** - Call insert function multiple times with different values
5. **Write a print function** - Loop through list starting at head, print each data value
6. **Write a search function** - Traverse list and return true if value is found
7. **Write a delete function** - Find the node to delete, adjust pointers to skip it, free memory
8. **Clean up** - Before program ends, delete all nodes to avoid memory leaks

## Common mistakes to avoid

- **Losing the head pointer** - Never move `head` during traversal. Use a separate `current` pointer.
- **Forgetting to set next to nullptr** - When creating the last node, always set `next = nullptr`.
- **Deleting a node without updating pointers** - First adjust pointers to skip over the node, THEN delete it.
- **Using -> instead of . (or vice versa)** - Use `->` for pointers: `ptr->data`. Use `.` for objects: `node.data`.
- **Not checking for nullptr** - Before accessing `node->data`, check if `node != nullptr` to avoid crashes.
- **Memory leaks from not deleting** - Every `new Node` must eventually have a `delete`. Clean up before program ends.
- **Following a nullptr** - If you write `current->next` when `current` is `nullptr`, the program crashes.
- **Losing nodes during insertion/deletion** - Save necessary pointers before changing them, or you'll lose access to parts of the list.

## Practice checklist

- [ ] I can define a Node structure with data and a next pointer.
- [ ] I can create a linked list by allocating nodes and linking them.
- [ ] I can traverse a linked list from head to end.
- [ ] I can insert a new node at the front of the list.
- [ ] I can delete a node from the list (updating pointers correctly).
- [ ] I can delete the entire list without memory leaks.
