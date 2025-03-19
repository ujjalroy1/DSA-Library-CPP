#include<bits/stdc++.h>
using namespace std;
int main()
{

 
    int n,i,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
         cin>>arr[i];
    }
    for(i=0;i<n-1;i++)
    {
         int x=i;
         for(j=i+1;j<n;j++)
         {
             if(arr[x]>arr[j])
             {
                 x=j;
             }
         }
         int temp=arr[x];
         arr[x]=arr[i];
         arr[i]=temp;
    }

      for(i=0;i<n;i++)
      {
         cout<<arr[i]<<" ";
      }
      cout<<endl;
    return 0;
}