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
ll dp[20][2][180];
ll func(ll indx,ll tight,ll sum,string &s)
{
      if(s.size()<=indx)return sum;
      if(dp[indx][tight][sum]!=-1)return dp[indx][tight][sum];
      ll limit;
      if(tight==1)
      {
         limit=s[indx]-'0';
      }
      else limit=9;
      ll ans=0;
      for(ll i=0;i<=limit;i++)
      {
        ll newtight=tight&(i==limit);
        ans+=func(indx+1,newtight,sum+i,s);

      }
     
      return dp[indx][tight][sum]=ans;


      

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    
     memset(dp,-1,sizeof(dp));
      ll l,r;
      cin>>l>>r;
      string l1=to_string(l-1);
      string l2=to_string(r);

      ll ans1=func(0,1,0,l2);
      memset(dp,-1,sizeof(dp));
      ll ans2=func(0,1,0,l1);

      cout<<ans1-ans2<<endl;
    

    return 0;
}