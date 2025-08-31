#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
int main()
{

   Node *first=new Node(10);
   cout<<first->data<<endl;

    return 0;
}