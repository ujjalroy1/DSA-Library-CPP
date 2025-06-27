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
   
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n];
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll,ll>>>> pq;

    ll vis[n]={0};
    ll sum=0;
    vector<pair<ll,ll>>ans;
    pq.push({0,{0,-1}});
    while (!pq.empty())
    {
        ll node=pq.top().second.first;
        ll par=pq.top().second.second;
        ll dist=pq.top().first;
        pq.pop();
        if(vis[node])continue;
        if(par!=-1)
        {
             sum+=dist;
             ans.push_back({par,node});
        }
        vis[node]=1;
        for(auto u:adj[node])
        {
            pq.push({u.second,{u.first,node}});

        }
    }
    cout<<sum<<endl;
    for(auto u:ans)
    {
         cout<<u.first<<" "<<u.second<<endl;
    }


    return 0;
}