// foo.cpp --- implement a trie

#include <iostream>
#include <string>

using namespace std;

class TNode
{
    bool Visited;
public:
    char Data;
    TNode* leftNode;
    TNode* rightNode;
    TNode(char data);
    bool visited();
    void appendLeft(char data);
    void appendRight(char data);
};

TNode::TNode(char data)
{
    char Data = data;
    leftNode = NULL;
    rightNode = NULL;
    Visited = false;
}

bool TNode::visited()
{
    return this->Visited;
}

void TNode::appendLeft(char data)
{
    TNode* appendedNode = this->leftNode;
    appendedNode = new TNode(data);
}

void TNode::appendRight(char data)
{
    TNode* appendedNode = this->rightNode;
    appendedNode = new TNode(data);
}

int main()
{
    cout<<"Let's make a trie. Which char goes into the root?"<<endl;
    char input;
    cin>>input;
    TNode head(input);
    TNode* node = &head;
    while(input!='#')
    {
        cout<<"Append to the tree. Left (L) or right (R)?"<<endl;
        cin>>input;
        if(input=='L')
        {
            cout<<"Which char?"<<endl;
            cin>>input;
            node->appendLeft(input);
            node = node->rightNode;
        } else if (input=='R') {
            cout<<"Which char?"<<endl;
            cin>>input;
            node->appendRight(input);
            node = node->rightNode;
        } else if (input=='P'){

        }
    }
    return 0;
}
