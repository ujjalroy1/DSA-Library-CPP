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

ll parent[100000], rank1[100000], Size[100000];
void setparent(ll n)
{
  parent[n] = n;
}
ll findparent(ll n)
{
  if (parent[n] == n)
    return n;
  return parent[n] = findparent(parent[n]);
}
void unionbyrank(ll u, ll v)
{
  ll a = findparent(u);
  ll b = findparent(v);
  if (a == b)
    return;
  if (rank1[a] < rank1[b])
  {
    parent[a] = b;
  }
  else if (rank1[b] < rank1[a])
  {
    parent[b] = a;
  }
  else
  {
    parent[b] = a;
    rank1[a]++;
  }
}
void unionBySize(ll u, ll v)
{
  ll a = findparent(u);
  ll b = findparent(v);
  if (a == b)
    return;
  if (Size[a] < Size[b])
  {
    parent[a] = b;
    Size[b] += Size[a];
  }
  else
  {
    parent[b] = a;
    Size[a] += Size[b];
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, m, i;
  cin >> n >> m;
  vector<pair<ll, pair<ll, ll>>> vp;
 for(i=0;i<=n;i++)
 {
   setparent(i);
   rank1[i]=1;
   Size[i]=0;
 }
  for (ll i = 0; i < m; i++)
  {
    ll u, v, w;
    cin >> u >> v >> w;
    vp.push_back({w, {u, v}});
  }
  sort(vp.begin(), vp.end());

    ll sum=0;
    vector<pair<ll,ll>>ans;
  for (i = 0; i < vp.size(); i++)
  {
      ll a=findparent(vp[i].second.first);
      ll b=findparent(vp[i].second.second);
      
      if(a==b)
      {
        continue;
      }
      ans.push_back({vp[i].second.first,vp[i].second.second});
      sum+=vp[i].first;
      unionbyrank(a,b);

  }

     cout<<sum<<endl;
     for(auto u:ans)
     {
       cout<<u.first<<" "<<u.second<<endl;
     }
  return 0;
}