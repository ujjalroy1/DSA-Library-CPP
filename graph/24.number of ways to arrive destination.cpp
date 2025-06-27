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
  


    ll n,m,i,j;
    cin>>n>>m;
    vector<pair<ll,ll>>adj[n+1];
    ll dis[n+1]={0};
    ll ways[n+1]={0};
    for(i=0;i<n;i++)
    {
         dis[i]=1e8;
    }
    for(i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    dis[0]=0;
    ways[0]=1;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,0});
    while (!pq.empty())
    {
        
        ll node=pq.top().second;
        ll dist=pq.top().first;
        pq.pop();
        for(auto u:adj[node])
        {
            if(dist+u.second<dis[u.first])
            {
                dis[u.first]=dist+u.second;
                pq.push({dist+u.second,u.first});
                ways[u.first]=ways[node];
            }
            else if((dist+u.second)==dis[u.first])
            {
                ways[u.first]+=ways[node];
            }

        }

    }
    cout<<ways[5]<<endl;
    


    return 0;
}