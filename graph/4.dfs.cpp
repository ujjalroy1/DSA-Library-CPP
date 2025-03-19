#include<bits/stdc++.h>

using namespace std;

int vis[100+1];

vector<int>adj[100+1];

void dfs(int node)

{

     vis[node]=1;

     cout<<node<<" ";

     for(auto u:adj[node])

     {

         if(vis[u])continue;

         dfs(u);

     }



}

int main()

{

 

      int n,m,i;

      cin>>n>>m;



      for(i=1;i<=m;i++)

      {

           int u,v;

           cin>>u>>v;

           adj[u].push_back(v);

           adj[v].push_back(u);



      }



     dfs(1);





    return 0;

}