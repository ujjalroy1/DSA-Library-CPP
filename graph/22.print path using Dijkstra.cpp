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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    ll n,m,i;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n];
    for(i=0;i<m;i++)
    {
         ll u,v,w;
         cin>>u>>v>>w;
         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,0});
    ll dis[n]={0};
    for(int i=0;i<n;i++)
    {
         dis[i]=(ll)1e18;
    }
    dis[0]=0;
    ll parent[n+1]={0};
    for(ll i=0;i<=n;i++)
    {
         parent[i]=i;
    }

    while(!pq.empty())
    {
        ll node=pq.top().second;
        ll wt=pq.top().first;
        pq.pop();
        for(auto child:adj[node])
        {
            if(child.second+wt<dis[child.first])
            {
                dis[child.first]=child.second+wt;
                pq.push({dis[child.first],child.first});
                parent[child.first]=node;

            }
        }
    }
    for(i=0;i<n;i++)
    {
         cout<<dis[i]<<" ";
    }
    cout<<endl;
    ll node=3;
    while(parent[node]!=node)
    {
          cout<<node<<endl;
          node=parent[node];
    }
    cout<<node<<endl;

    return 0;
}
