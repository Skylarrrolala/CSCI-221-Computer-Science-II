// Based on Display 13.17 (modified: char -> int)
#ifndef STACK_H
#define STACK_H

struct StackFrame
{
    int data;
    StackFrame *link;
};

typedef StackFrame* StackFramePtr;

class Stack
{
public:
    Stack();
    Stack(const Stack& a_stack);
    ~Stack();
    void push(int the_symbol);
    int pop();
    bool empty() const;
private:
    StackFramePtr top;
};

#endif
