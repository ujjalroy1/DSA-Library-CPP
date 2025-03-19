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
         ans+=r*r*r;
         n/=10;

     }
     
    if(x==ans)
    {
         cout<<"Armstrongn";
    }
    else cout<<"Not Armstrongn";


    return 0;
}