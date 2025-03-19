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
   
     ll n,m,i,j;
     cin>>n>>m;
     ll arr[n][m];
     ll vis[n][m];
     queue<pair<ll,pair<ll,ll>>>q;
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
             cin>>arr[i][j];
             vis[i][j]=0;
             if(arr[i][j]==2)
             {
                 vis[i][j]=1;
                 q.push({i,{j,0}});
             }
         }
     }
     ll ans1=0;
     while(!q.empty())
     {
        ll ii=q.front().first;
        ll jj=q.front().second.first;
        ll tim=q.front().second.second;
        ans1=max(ans1,tim);
        q.pop();
        if(i-1>=0&&vis[i-1][j]==0&&arr[i-1][j]==1)
        {
             vis[i-1][j]=1;
             arr[i-1][j]=2;
             q.push({i-1,{j,tim+1}});
        }
        if(j+1<m&&vis[i][j+1]==0&&arr[i][j+1]==1)
        {
             vis[i][j+1]=1;
             arr[i][j+1]=2;
             q.push({i,{j+1,tim+1}});
        }
        if(i+1<n&&vis[i+1][j]==0&&arr[i+1][j]==1)
        {
             vis[i+1][j]=1;
             arr[i+1][j]=2;
             q.push({i+1,{j,tim+1}});
        }
        if(j>=0&&vis[i][j-1]==0&&arr[i][j-1]==1)
        {
             vis[i][j-1]=1;
             arr[i][j-1]=2;
             q.push({i,{j-1,tim+1}});
        }
     }
     ll ans=0;
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
             if(arr[i][j]==1)
             {
                 ans=1;
                 break;
             }
         }
     }
     if(ans==1)cout<<-1<<endl;
     else cout<<ans1<<endl;

    return 0;
}