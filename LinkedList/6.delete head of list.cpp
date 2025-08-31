#include <bits/stdc++.h>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
Node *arraytolist(vector<int> &v)
{

    Node *head = new Node(v[0]);
    Node *move = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newnode = new Node(v[i]);
        move->next = newnode;
        move = newnode;
    }

    return head;
}
Node *deletefirstnode(Node *head)
{
    Node *temp=head;
    head=head->next;
    delete temp;

    return head;
}
int main()
{

    vector<int> v = {10, 2, 3, 4, 5};
    Node *head = arraytolist(v);

    head=deletefirstnode(head);

     while (head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return 0;
}