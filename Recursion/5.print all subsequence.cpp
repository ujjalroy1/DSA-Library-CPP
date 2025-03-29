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
void func(ll i,ll arr[],vector<ll>&ans,ll n)
{
    if(i==n)
    {
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[j]<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);
    func(i+1,arr,ans,n);
    ans.pop_back();
    func(i+1,arr,ans,n);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
     int n,i;
     cin>>n;
     ll arr[n];
     for(i=0;i<n;i++)
     {
         cin>>arr[i];
     }
     vector<ll>ans;
     func(0,arr,ans,n);

    return 0;
}