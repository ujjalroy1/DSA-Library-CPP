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
   
    //declaration
    vector<int>v;
    v.push_back(1);
    v.emplace_back(3);
    cout<<v.size()<<endl;

    vector<pair<int,int>>vp;
    vp.push_back({1,2});
    vp.emplace_back(2,3);
    cout<<vp.size()<<endl;
  
    vector<int>vv(10);
    vector<int>vvs(10,5);
    for(auto u:vvs)cout<<u<<endl;

    vector<int>vc(v);
    cout<<vc.size()<<endl;

    cout<<vc.back()<<endl;

    vector<int>::iterator it=v.begin();
    for(it;it!=v.end();it++)cout<<*(it)<<" ";
    cout<<endl;

    for(auto u:v)cout<<u<<" ";
    cout<<endl;
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);

   //Erase
   v.erase(v.begin()+1);
   v.erase(v.begin(),v.end());//end not included erase before end
   cout<<v.size()<<endl;

   //insert
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.insert(v.begin()+1,100);
    for(auto u:v)cout<<u<<" ";
    cout<<endl;

    v.insert(v.begin()+2,2,200);//two occurance of 200 in position 2(0base)
    for(auto u:v)cout<<u<<" ";
    cout<<endl;

    v.pop_back();//erase last element
    
    return 0;
}