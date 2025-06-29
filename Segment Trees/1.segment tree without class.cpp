#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class type1>
#define ll long long int
#define endl "\n"
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using ordered_multiset = tree<type1, null_type, less_equal<type1>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_multiset <ll> kek;(declaration for multiorder set)
// ordered_set o_set;(declaration)
// kek.order_of_key(i);(strictly less then i for multi order set)
// o_set.order_of_key(5) ;(strictly less then i for multi order set)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define mod 1000000007
ll POW(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2)
            ans = (ans * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return ans;
}
void build(ll indx, ll low, ll high, ll arr[], ll seg[])
{
    if (low == high)
    {
        seg[indx] = arr[low];
        return;
    }
    ll mid = (low + high) / 2;
    build(2 * indx + 1, low, mid, arr, seg);
    build(2 * indx + 2, mid + 1, high, arr, seg);

    seg[indx] = min(seg[2 * indx + 1], seg[2 * indx + 2]);
}
ll query(ll indx, ll low, ll high, ll l, ll r, ll arr[], ll seg[])
{
    if (high < l || low > r)
        return (ll)1e12;
    else if (l <= low && high <= r)
    {

        return seg[indx];
    }
    ll mid = (low + high) / 2;
    ll left = query(2 * indx + 1, low, mid, l, r, arr, seg);
    ll right = query(2 * indx + 2, mid + 1, high, l, r, arr, seg);
    return min(left, right);
}
void update(ll indx,ll low ,ll high,ll i,ll val, ll seg[])
{
     if(low==high)
     {
         seg[indx]=val;
         return;
     }
     ll mid=(low+high)/2;
     if(i<=mid)
     {
         update(2*indx+1,low,mid,i,val,seg);

     }
     else
     {
                 update(2*indx+2,mid+1,high,i,val,seg);

     }
     seg[indx] = min(seg[2 * indx + 1], seg[2 * indx + 2]);

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, i;
    cin >> n;
    ll arr[n];
    ll seg[4 * n];

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1, arr, seg);

    ll q;
    cin >> q;
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r, arr, seg) << endl;
        }
        else
        {
              ll ind,val;
              cin>>ind>>val;
              update(0,0,n-1,ind,val,seg);
              arr[ind]=val;

        }
    }

    return 0;
}