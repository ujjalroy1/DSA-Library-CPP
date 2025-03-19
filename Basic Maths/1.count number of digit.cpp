#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    int original_n = n; 
    int cnt = 0;
    
    while (n > 0)
    {
        cnt += 1;
        n /= 10;
    }
    cout << cnt << endl;

    
    cnt = (original_n == 0) ? 1 : (int)(log10(original_n) + 1);

    cout << cnt << endl;
}
