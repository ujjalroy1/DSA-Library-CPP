
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int arr[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             cin>>arr[i][j];
             if(arr[i][j]==-1)
             {
                arr[i][j]=(int)1e8;
             }
             if(i==j)
             {
                 arr[i][j]=0;
             }

        }
    }

    for(int k=0;k<n;k++)
    {
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
             }
         }
    }
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
        if(arr[i][j]==(int)1e8)cout<<"Inf ";
        else cout<<arr[i][j]<<" ";
     }
     cout<<endl;
   }





    return 0;
}