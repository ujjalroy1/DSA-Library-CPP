#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class type1>
#define ll long long int
#define endl "\n"
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
 //ordered_multiset <ll> kek;(declaration for multiorder set)
// ordered_set o_set;(declaration)
//kek.order_of_key(i);(strictly less then i for multi order set)
//o_set.order_of_key(5) ;(strictly less then i for multi order set)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define mod 1000000007
ll POW(ll a,ll b)
{   ll ans=1;
   while(b>0)
   {   if(b%2)ans=(ans*a)%mod;
       b/=2;
       a=(a*a)%mod;
   }
   return ans;
}
ll timee=0;
void dfs(ll node,ll parent,ll vis[],ll tin[],ll low[],ll mark[],vector<ll>adj[])
{
    vis[node]=1;
    tin[node]=timee;
    low[node]=timee;
    timee++;
    ll child=0;
    for(auto u:adj[node])
    {
        if(u==parent)continue;
        if(vis[u]==0)
        {
            
             dfs(u,node,vis,tin,low,mark,adj);
             low[node]=min(low[node],low[u]);
             if(low[u]>=tin[node]&&parent!=-1)
             {
                 mark[node]=1;
             }
             child++;
        }
        else
        {
            low[node]=min(low[node],tin[u]);

        }
    }
    if(child>1&&parent==-1)
    {
         mark[node]=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n,m,i,j;
    cin>>n>>m;
    vector<ll>adj[n];
    for(i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll tin[n];
    ll low[n];
    ll vis[n]={0};
    ll mark[n]={0};
    
    vector<ll>ans;
    for(i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            
            dfs(i,-1,vis,tin,low,mark,adj);
        }
    }
    for(i=0;i<n;i++)
    {
        if(mark[i]==1)
        {
             ans.push_back(i);
        }
    }
    if(ans.size()==0)
    {
         cout<<"No Artculation point\n";
         return 0;
    }
    for(auto u:ans)
    {
         cout<<u<<" ";
    }

    return 0;
}