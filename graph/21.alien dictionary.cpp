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
   
    vector<string>vs;
    ll n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
         string s;
         cin>>s;
         vs.push_back(s);
    }

    vector<ll>adj[100];
    stack<ll>st;
    ll vis[100]={0};
    ll indeg[100]={0};

     for(i=0;i<n-1;i++)
     {
        for(ll j=0;j<min(vs[i].size(),vs[i+1].size());j++)
        {
            if(vs[i][j]!=vs[i+1][j])
            {
                adj[vs[i][j]-'a'].push_back(vs[i+1][j]-'a');
                break;
            }
        }
     }
     for(i=0;i<4;i++)
     {
         for(auto u:adj[i])
         {
             cout<<u<<" ";
         }
     }
     queue<ll>q;
    for(i=0;i<4;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        ll node=q.front();
        cout<<(char)(node+'a')<<" ";
        q.pop();
        for(auto u:adj[node])
        {
            indeg[u]--;
            if(indeg[u]<=0)
            {
                 q.push(u);
            }
        }
    }
    


    return 0;
}