#include <iostream>
#include <cstddef>
#include "head_insert.h"
#include "stack.h"
using namespace std;

// Reverses the linked list by pushing data onto a stack
// and popping it back. No nodes are created or destroyed.
void reverse(NodePtr& head);

void print_list(NodePtr head);

int main()
{
    NodePtr head = NULL;

    // Build list: 1 -> 2 -> 3 -> 4 -> 5
    // head_insert adds to the front, so insert in reverse order
    head_insert(head, 5);
    head_insert(head, 4);
    head_insert(head, 3);
    head_insert(head, 2);
    head_insert(head, 1);

    cout << "Original list: ";
    print_list(head);

    reverse(head);

    cout << "Reversed list: ";
    print_list(head);

    // Clean up memory
    NodePtr temp;
    while (head != NULL)
    {
        temp = head;
        head = head->link;
        delete temp;
    }

    return 0;
}

void reverse(NodePtr& head)
{
    if (head == NULL)
        return;

    Stack s;
    NodePtr current = head;

    // Traverse the list, pushing each value onto the stack
    while (current != NULL)
    {
        s.push(current->data);
        current = current->link;
    }

    // Traverse again, popping values back (now in reverse order)
    current = head;
    while (current != NULL)
    {
        current->data = s.pop();
        current = current->link;
    }
}

void print_list(NodePtr head)
{
    NodePtr current = head;
    while (current != NULL)
    {
        cout << current->data;
        if (current->link != NULL)
            cout << " -> ";
        current = current->link;
    }
    cout << endl;
}
