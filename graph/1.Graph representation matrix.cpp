#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main()

{

    ll n,m,i,j;

    cin>>n>>m;

    ll adj[n+1][m+2];

   for(i=0;i<=n;i++)

   {

     for(j=0;j<=m;j++)

     {

       adj[i][j]=0;

     }

    

   }

   for(i=1;i<=m;i++)

   {

       ll u,v;

       cin>>u>>v;

       adj[u][v]=1;

       adj[v][u]=1;

   }

   for(i=0;i<=n;i++)

   {

     for(j=0;j<=m;j++)

     {

         cout<<adj[i][j]<<" ";

     }

     cout<<endl;

   }

    return 0;

}