#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n;
     cin>>n;
     if(n==1||n==0)
     {
         cout<<"Not prime\n";
         return 0;
     }
     int flag=0;
     for(int i=2;i*i<=n;i++)
     {
         if(n%i==0)
         {
             flag=1;
             break;
         }
     }
     if(flag==0)cout<<"Prime\n";
     else cout<<"Not prime\n";

    return 0;
}