// Based on Display 13.4 (modified: char -> int)
#ifndef HEAD_INSERT_H
#define HEAD_INSERT_H

struct Node
{
    int data;
    Node *link;
};

typedef Node* NodePtr;

void head_insert(NodePtr& head, int the_number);

#endif
