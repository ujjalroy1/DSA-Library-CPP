#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main()

{

    ll n,m,i,j;

    cin>>n>>m;

    vector<int>adj[n+1];

  

   for(i=1;i<=m;i++)

   {

       ll u,v;

       cin>>u>>v;

       adj[u].push_back(v);

       adj[v].push_back(u);

   }

   for(i=0;i<=n;i++)

   {

     cout<<i<<"-->";

      for(j=0;j<adj[i].size();j++)

      {

         cout<<adj[i][j]<<" ";

      }

      cout<<endl;

   }

    return 0;

}