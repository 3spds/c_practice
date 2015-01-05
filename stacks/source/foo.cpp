#include "./foo.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    Node* top = NULL;
    top = new Node(-1);
}

int Stack::pop()
{
    if(top!=NULL)
    {
        int item = top->data;
        top->removeNode();
        return item;
    }
};

void Stack::push(int item)
{
    Node* newTop = NULL;
    newTop = new Node(item);
    newTop->next = top;
    top = newTop;
}

int main()
{
    Stack* foo = new Stack();
    cout<<"push int to stack? -1 to stop."<<endl;
    int input;
    cin>>input;
    while(input>=0)
    {
        foo->push(input);
        cout<<"new stack: ";
        foo->top->printAll();
        cout<<endl;
        cin>>input;
    }
    cout<<"pop int from stack? 1 for next, -1 for stop."<<endl;
    cin>>input;
    while(input==1)
    {
        cout<<foo->pop()<<endl;
        cout<<"new stack: ";
        foo->top->printAll();
        cout<<endl;
        cin>>input;
    }
    cout<<"fin."<<endl;
    return 0;
}
