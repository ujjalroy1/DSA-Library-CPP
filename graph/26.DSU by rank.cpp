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
ll parent[100000],rank1[100000],Size[100000];
void setparent(ll n)
{
    parent[n]=n;
}
ll findparent(ll n)
{
    if(parent[n]==n)return n;
    return parent[n]=findparent(parent[n]);
}
void unionbyrank(ll u,ll v)
{
    ll a=findparent(u);
    ll b=findparent(v);
    if(a==b)return;
    if(rank1[a]<rank1[b])
    {
        parent[a]=b;
    }
    else if(rank1[b]<rank1[a])
    {
        parent[b]=a;
    }
    else
    {
        parent[b]=a;
        rank1[a]++;
    }
}
    void unionBySize(ll u,ll v)
    {
          ll a=findparent(u);
          ll b=findparent(v);
          if(a==b)return;
          if(Size[a]<Size[b])
          {
               parent[a]=b;
               Size[b]+=Size[a];
          }
          else
          {
                    parent[b]=a;
                  Size[a]+=Size[b];
          }
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    ll n;
    cin>>n;
    for(ll i=0;i<=n;i++)
    {
        setparent(i);
    }

    unionbyrank(1,2);
    unionbyrank(2,3);
    unionbyrank(4,5);
    unionbyrank(6,5);
    unionbyrank(6,7);

    if(findparent(3)==findparent(7))
    {
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    unionbyrank(3,7);
      if(findparent(2)==findparent(7))
    {
        cout<<"Yes\n";
    }
    else cout<<"No\n";
    return 0;
}