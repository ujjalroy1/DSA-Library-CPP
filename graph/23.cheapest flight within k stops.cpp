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
   
   ll n,m,k,i;
   cin>>n>>m>>k;
   vector<pair<ll,ll>>adj[n+1];
   for(i=0;i<m;i++)
   {
     ll u,v,w;
     cin>>u>>v>>w;
     adj[u].push_back({v,w});

   }
   
   vector<ll>dist(n+1,1e18);
   priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
   pq.push({0,{0,0}});
   dist[0]=0;
   while (!pq.empty())
   {
     ll cnt=pq.top().first;
     ll node=pq.top().second.first;
     ll dis=pq.top().second.second;
     pq.pop();

     if(cnt>k)continue;
     for(auto u:adj[node])
     {
        ll adjnode=u.first;
        ll cost=u.second;
        if(dis+cost<dist[adjnode])
        {
            dist[adjnode]=dis+cost;
            pq.push({cnt+1,{adjnode,dist[adjnode]}});
        }

     }


    
   }
   

      cout<<dist[2]<<endl;

    return 0;
}