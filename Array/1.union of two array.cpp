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
   
     int n,m,i;
     cin>>n>>m;
     map<ll,ll>mp;
     ll arr[n],brr[n];
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
         mp[arr[i]]++;
     }
    for(int i=0;i<m;i++)
     {
         cin>>brr[i];
         mp[brr[i]]++;
     }
     vector<ll>ans;
     for(auto u:mp)
     {
        ans.push_back(u.first);
     }
     for(int i=0;i<ans.size();i++)
     {
         cout<<ans[i]<<" ";
     }
     
    return 0;
}