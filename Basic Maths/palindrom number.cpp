#include<bits/stdc++.h>
using namespace std;
int main()
{
 
     int n;
     cin>>n;
     int ans=0;
     int x=n;
     while (n>0)
     {
       
         int r=n%10;
         ans=(ans*10)+r;
         n/=10;

     }
     
    if(x==ans)
    {
         cout<<"palindrom\n";
    }
    else cout<<"Not palindrom\n";


    return 0;
}