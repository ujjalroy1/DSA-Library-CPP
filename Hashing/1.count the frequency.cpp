#include<bits/stdc++.h>
using namespace std;
int main()
{
 
     int n;
     cin>>n;
     int count[1000]={0};
     for(int i=0;i<n;i++)
     {
         int x;
         cin>>x;
         count[x]++;
     }
     int q;
     cin>>q;
     while (q--)
     {
        int x;
        cin>>x;
        cout<<count[x]<<endl;
     }
     


    return 0;
}