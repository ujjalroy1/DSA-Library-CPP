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
ll vis[1000][1000];
ll adj[1000][1000];
void dfs(ll row,ll col,vector<pair<ll,ll>>&vp,ll brow,ll bcol,ll n,ll m)
{
    vis[row][col]=1;
    vp.push_back({brow-row,bcol-col});
    ll dr[]={-1,0,1,0};
    ll dc[]={0,1,0,-1};
    for(ll i=0;i<4;i++)
    {
         ll nrow=row+dr[i];
         ll ncol=col+dc[i];
         if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&adj[nrow][ncol]==1)
         {
            dfs(nrow,ncol,vp,brow,bcol,n,m);
         }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
     ll n,m,i,j;
     cin>>n>>m;
    set<vector<pair<ll,ll>>>st;
    for(i=0;i<n;i++)
    {
         for(j=0;j<m;j++)
         {
             cin>>adj[i][j];
         }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             if(vis[i][j]==0&&adj[i][j]==1)
             {
                 vector<pair<ll,ll>>vp;
                dfs(i,j,vp,i,j,n,m);
                st.insert(vp);
             }
        }
    }
   cout<<st.size()<<endl;

    return 0;
}