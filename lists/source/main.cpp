#include "./bar.cpp"
#include <iostream>

using namespace std;

int main()
{
    int input;
    cin>>input;
    Node* head = NULL;
    head = new Node(input);
    cin>>input;
    while(input > -1)
    {
        head->appendNode(input);
        head->printAll();
        cin>>input;
    }
    cout<<"done appending! now goto..."<<endl;
    cin>>input;
    while(input > -1)
    {
        cout<<head->goToNode(input)->data<<endl;
        cin>>input;
    }
    cout<<"done goto! now removeNode..."<<endl;
    cin>>input;
    while(input > -1)
    {
        head->goToNode(input)->removeNode();
        head->printAll();
        cin>>input;
    }
    cout<<"done removeNode! now removeAt..."<<endl;
    cin>>input;
    while(input>-1)
    {
        head->removeAt(input);
        if(head!=NULL) head->printAll();
        cin>>input;
    }
    cout<<"exit."<<endl;
    return 0;
}
