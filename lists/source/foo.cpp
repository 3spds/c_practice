#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
    void append(int d){
        Node* last = NULL;
        last = new Node(d);
        Node* n = this;
        while(n->next != NULL){
            n = n->next;
        }
        n->next = last;
    }
    void removeNode(){
        Node* n = this;
        while(n->next->next != NULL){
            n->data = n->next->data;
            n=n->next;
        }
        n->data = n->next->data;
        n->next = NULL;
    }
    void printAll(){
        Node* n = this;
        while(n != NULL){
            cout<<n->data<<" ";
            n = n->next;
        }
        cout<<endl;
    }
};



int main()
{
    Node* head = NULL;
    head = new Node(1);
    for(int i=0;i<10;i++){
        head->append(i+2); //since we already started with 1..
    }
    head->printAll();
    head->next->next->removeNode();
    head->printAll();
    return 0;
}
