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
int getCount(Node *head)
{

    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
bool searchKey(Node *head, int key)
{

    while (head)
    {
        if (head->data == key)
            return true;
        head = head->next;
    }
    return false;
}
int main()
{

    vector<int> v = {10, 2, 3, 4, 5};
    Node *head = arraytolist(v);
 
    if(searchKey(head,10))cout<<"Found\n";
    else cout<<"Not Found\n";
  
    return 0;
}