
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool dfs(ll node,ll col,vector<ll>adj[],vector<ll>&vis)
{
    vis[node]=col;
    for(auto child:adj[node])
    {
        if(vis[child]==-1)
        {
            if(dfs(child,!col,adj,vis)==false)return false;
        }
        if(vis[child]==col)
        {
            //cout<<vis[child]<<node<<" "<<child<<endl;
            return false;

        }
    }
    return true;
}
int main()
{
  
   
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    for(ll i=0;i<m;i++)
    {
         ll u,v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }
   vector<ll>vis(n+1);
    for(ll i=1;i<=n;i++)
    {
         vis[i]=-1;
    }
    ll ok=0;
    for(ll i=1;i<=n;i++)
    {
       if(vis[i]==-1)
       {
          if(dfs(i,0,adj,vis)==false)
          {
            
               cout<<"Not bipartite\n";
               ok=1;
               break;

          }
       }
    }
    if(ok==0)
    {
        cout<<"Bipartite\n";
    }


    return 0;
}