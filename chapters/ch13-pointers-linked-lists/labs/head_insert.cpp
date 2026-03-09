// Based on Display 13.4 (modified: char -> int)
#include <cstddef>
#include "head_insert.h"

void head_insert(NodePtr& head, int the_number)
{
    NodePtr temp_ptr;
    temp_ptr = new Node;
    temp_ptr->data = the_number;
    temp_ptr->link = head;
    head = temp_ptr;
}
