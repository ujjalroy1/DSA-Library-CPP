#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class type1>
#define ll long long int
#define endl "\n"
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using ordered_multiset = tree<type1, null_type, less_equal<type1>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_multiset <ll> kek;(declaration for multiorder set)
// ordered_set o_set;(declaration)
// kek.order_of_key(i);(strictly less then i for multi order set)
// o_set.order_of_key(5) ;(strictly less then i for multi order set)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define mod 1000000007
ll POW(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * a) % mod;
        b /= 2;
        a = (a * a) % mod;
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
    vector<ll>adj[n+1];
    ll color[n+1];
    for(i=1;i<=n;i++)
    {
        color[i]=-1;
    }
    for(i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans=0;
    for(ll j=1;j<=n;j++)
    {
        if(color[j]==-1)
        {
            queue<ll>q;
            q.push(i);
            color[i]=0;
            while (!q.empty())
            {
                ll node=q.front();
                q.pop();
                for(i=0;i<adj[node].size();i++)
                {
                    if(color[adj[node][i]]==-1)
                    {
                         color[adj[node][i]]=!color[node];
                    }
                    else if(color[adj[node][i]]==color[node])
                    {
                        ans=1;
                        break;
                    }
                }
                if(ans)break;
            }
            
        }
        if(ans)break;
    }

  if(ans)
  {
     cout<<"Not Bipartite\n";
  }
  else cout<<"Bipartite\n";
    return 0;
}