#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int d);
    void appendNode(int d);
    void removeNode(void);
    void removeAt(int index);
    void printAll();
    Node* goToNode(int index);
};

Node::Node(int d)
{
    data = d;
    next = NULL;
}

void Node::appendNode(int d)
{
    Node* n = this;
    Node* last = NULL;
    last = new Node(d);
    while(n->next != NULL)
    {
        n = n->next;
    }
    n->next = last;
}

void Node::printAll()
{
    Node* n = this;
    while(n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

void Node::removeNode()
{
    Node* n = this;
    if(n == NULL || n->next == NULL) // end of list, use a dummy node
    {
        cout<<"WELL SLAP MY ASS AND CALL ME SALLY"<<endl;
        n->data = -1;
        n->next = NULL;
    } else { // next-to-end of list
        while(n->next->next!=NULL) // more than two away from end
        {
            n->data = n->next->data;
            n = n->next;
        }
        n->data = n->next->data;
        n->next = NULL;
    }
}

void Node::removeAt(int index)
{
    Node* n = this;
    if(index == 0)
    {
        if(n->next!=NULL)
        {
            *n = *(n->next);
        }
    } else {
        n = n->goToNode(index-1);
        if(n->next!=NULL)
        {
            n->next = n->next->next;
        } else {
            n->next = NULL;
        }
    }
}

Node* Node::goToNode(int index)
{
    Node* n = this;
    for(int i = 0; i<index; i++)
    {
        if(n->next!=NULL) n = n->next;
    }
    return n;
}
