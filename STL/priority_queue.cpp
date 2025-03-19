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
   
     priority_queue<int>pq;
     pq.push(1);
     pq.push(2);
     pq.push(3);
     cout<<pq.top()<<endl;
     pq.pop();
     cout<<pq.top()<<endl;

     priority_queue<int,vector<int>,greater<int>>pq1;
     pq1.push(1);
     pq1.push(2);
     pq1.push(3);
     cout<<pq1.top()<<endl;
     pq1.pop();
     cout<<pq1.top()<<endl;
     cout<<pq1.size()<<endl;
     cout<<pq1.empty()<<endl;


    return 0;
}