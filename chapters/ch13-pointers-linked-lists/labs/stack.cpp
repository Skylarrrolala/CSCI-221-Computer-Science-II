// Based on Display 13.18 (modified: char -> int)
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include "stack.h"
using namespace std;

Stack::Stack() : top(NULL)
{
    // intentionally empty
}

Stack::Stack(const Stack& a_stack)
{
    if (a_stack.empty())
        top = NULL;
    else
    {
        StackFramePtr temp = a_stack.top;
        StackFramePtr end;
        top = new StackFrame;
        top->data = temp->data;
        end = top;
        temp = temp->link;
        while (temp != NULL)
        {
            end->link = new StackFrame;
            end = end->link;
            end->data = temp->data;
            temp = temp->link;
        }
        end->link = NULL;
    }
}

Stack::~Stack()
{
    int next;
    while (!empty())
        next = pop();
}

void Stack::push(int the_symbol)
{
    StackFramePtr temp_ptr;
    temp_ptr = new StackFrame;
    temp_ptr->data = the_symbol;
    temp_ptr->link = top;
    top = temp_ptr;
}

int Stack::pop()
{
    if (empty())
    {
        cout << "Error: popping an empty stack.\n";
        exit(1);
    }

    int result = top->data;
    StackFramePtr temp_ptr;
    temp_ptr = top;
    top = top->link;
    delete temp_ptr;

    return result;
}

bool Stack::empty() const
{
    return (top == NULL);
}
