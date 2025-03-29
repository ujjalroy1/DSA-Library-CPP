#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll arr[5];

void mergearr(ll l, ll r)

{

    ll mid, i;

    mid = (l + r) / 2;

    ll left[mid - l + 2], right[r - mid + 1];

    ll j = 0;

    for (i = l; i <= mid; i++)

    {

        left[j] = arr[i];

        j++;
    }

    left[mid - l + 1] = 100000000000;

    j = 0;

    for (i = mid + 1; i <= r; i++)

    {

        right[j] = arr[i];

        j++;
    }

    j = 0;

    ll k = 0;

    right[r - mid] = 100000000000;

    for (i = l; i <= r; i++)

    {

        if (left[j] <= right[k])

        {

            arr[i] = left[j];

            j++;
        }

        else

        {

            arr[i] = right[k];

            k++;
        }
    }
}

void mergesort(ll l, ll r)

{

    if (l == r)
        return;

    ll mid;

    mid = (l + r) / 2;

    mergesort(l, mid);

    mergesort(mid + 1, r);

    mergearr(l, r);
}

int main()

{

    ll n, i;

    arr[0] = 10;

    arr[1] = 7000000;

    arr[2] = 12000;

    arr[3] = 2;

    arr[4] = 1;

    mergesort(0, 4);

    for (i = 0; i < 5; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
