#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define endl "\n"

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define mod 1000000007

ll POW(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b % 2) ans = (ans * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    ll n, m;
    cin >> n >> m;

    // vector<vector<ll>> vis(n, vector<ll>(m, 0));
    // vector<vector<ll>> adj(n, vector<ll>(m));
      ll adj[n][m];
      ll vis[n][m];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> adj[i][j];
            vis[i][j]=0;
        }
    }
  


    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (adj[i][j] == 1 && vis[i][j] == 0) {
              
                ans++;
                queue<pair<ll, ll>> q;
                q.push({i, j});
                vis[i][j] = 1;

                while (!q.empty()) {
                    ll nrow = q.front().first;
                    ll ncol = q.front().second;
                    q.pop();

                    for (ll k = -1; k <= 1; k++) {
                        for (ll l = -1; l <= 1; l++) {
                            ll xrow = nrow + k;
                            ll xcol = ncol + l;

                            if (xrow >= 0 && xrow < n && xcol >= 0 && xcol < m) {
                                if (adj[xrow][xcol] == 1 && vis[xrow][xcol] == 0) {
                                    q.push({xrow, xcol});
                                    vis[xrow][xcol] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
