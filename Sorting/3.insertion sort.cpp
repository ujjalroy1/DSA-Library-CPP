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
    for(i=0;i<n;i++)
    {
        j=i;
        while (j>0&&(arr[j-1]>arr[j]))
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
        
    }

     for(i=0;i<n;i++)
     {
         cout<<arr[i]<<" ";
     }


    return 0;
}