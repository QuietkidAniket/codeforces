#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = false;
static const int mod = 1e9 + 7;

void Solve()
{
    int n = 7;
    ll k = 0ll;
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int i2 = 0; i2 < i1; i2++)
        {
            for (int i3 = 0; i3 < i2; i3++)
            {
                for (int i4 = 0; i4 < i3; i4++)
                {
                    for (int i5 = 0; i5 < i4; i5++)k = k + 1;
                }
            }
        }
    }
    // for(int i1 = 0; i6 < i5; i6++)k
    cout << k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    int tt = clock();
#endif

    int t = 1;
    if (multi)
        cin >> t;
    while (t--)
    {
        Solve();
        cout << endl;
    }
#ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
#endif
    return 0;
}