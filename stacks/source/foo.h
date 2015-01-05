// ./stacks/source/foo.h -- implements a stack
#include "../../lists/source/bar.cpp"

class Stack
{
public:
    Node* top;
    Stack();
    ~Stack();
    int pop();
    void push(int item);
    int peek();
};
