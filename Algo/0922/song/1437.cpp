#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 10007;
signed main()
{
    int n;
    cin >> n;
    int ans = 1;
    if (n % 3 == 0)
    {

        for (int i = 0; i < n / 3; i++)
        {
            ans *= 3;
            ans %= mod;
        }
    }
    else if (n % 3 == 1)
    {
        for (int i = 0; i < (n / 3) - 1; i++)
        {
            ans *= 3;
            ans %= mod;
        }
        ans *= 2;
        ans %= mod;
        ans *= 2;
        ans %= mod;
    }
    else if(n%3 == 2)
    {
        for (int i = 0; i < (n / 3); i++)
        {
            ans *= 3;
            ans %= mod;
        }
        ans *= 2;
        ans %= mod;
    }
    if(n == 0)
        ans = 0;
    if(n == 1)
        ans = 1;
    cout << ans%mod;
}
