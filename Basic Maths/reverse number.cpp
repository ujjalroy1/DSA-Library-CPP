#include<bits/stdc++.h>
using namespace std;
int main()
{
 
     int n;
     cin>>n;
     int ans=0;
     while (n>0)
     {
       
         int r=n%10;
         ans=(ans*10)+r;
         n/=10;

     }
     
     cout<<ans<<endl;


    return 0;
}