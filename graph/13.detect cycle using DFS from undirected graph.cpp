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
bool dfs(ll node,ll parent,vector<ll>adj[],ll vis[])
{
    vis[node]=1;
    for(auto child :adj[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child,node,adj,vis)==true)return true;
        }
        else if(child!=parent)
        {
            return true;
        }
    }
    return false;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    ll n,m,i,j;
    cin>>n>>m;
    vector<ll>adj[n];
    ll vis[n+1]={0};
    ll ok=0;
   
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
 
    if(dfs(0,-1,adj,vis))
    {
         cout<<"Cycle\n";
    }
    else cout<<"NO Cycle\n";



    return 0;
}