#include<bits/stdc++.h>
using namespace std;
void func(int i)
{
    if(i==3)return;
    cout<<i<<" ";
    func(i+1);
}
int main()
{

    int i=1;
    func(i);
}