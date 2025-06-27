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
    ll adj[n][m];
    ll vis[n][m];
    for(i=0;i<n;i++)
    {
         for(j=0;j<m;j++)
         {
             vis[i][j]=0;
             cin>>adj[i][j];
         }
    } 
    queue<pair<ll,ll>>q;
    for(i=0;i<n;i++)
    {
         for(j=0;j<m;j++)
         {
            if(i==0||j==0||i==n-1||j==m-1)
            {
                if(adj[i][j]==1)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
         }
    }
    ll dr[]={-1,0,1,0};
    ll dc[]={0,1,0,-1};

   while (!q.empty())
   {
      ll row=q.front().first;
      ll col=q.front().second;
      q.pop();
      for(ll i=0;i<4;i++)
      {
         
             ll nr=row+dr[i];
             ll nc=col+dc[i];
           if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&adj[nr][nc]==1)
           {
               q.push({nr,nc});
               vis[nr][nc]=1;
           }
      }

    
   }
   ll ans=0;
   for(i=0;i<n;i++)
   {
     for(j=0;j<m;j++)
     {
         if(adj[i][j]==1&&vis[i][j]==0)
         {
               ans++;
         }
     }
   }
   cout<<ans<<endl;


    return 0;
}