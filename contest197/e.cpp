/**
 *    author: Anicetus_7
 *    created: 2025-07-30 21:44:08
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

ld get_dp1(int n, const vector<int>& a, const vector<int>& b, ld E) {
    vector<ld> dp(n + 2, 0.0);
    dp[n + 1] = 0.0;
    for (int i = n; i >= 1; --i) {
        dp[i] = min((ld)a[i] + dp[i + 1], (ld)b[i] + E);
    }
    return dp[1];
}

bool too_low(int n, const vector<int>& a, const vector<int>& b, ld E) {
    vector<ld> dp(n + 2, 0.0);
    dp[n + 1] = 0.0;
    ld sum = 0.0;
    for (int i = n; i >= 1; --i) {
        dp[i] = min((ld)a[i] + dp[i + 1], (ld)b[i] + E);
        sum += dp[i];
    }
    ld avg = sum / (n + 1);
    return avg > E;
}

void Solve(){
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    ld lo = 0.0, hi = 4e11;
    for (int it = 0; it < 100; ++it) {
        ld mid = (lo + hi) / 2;
        if (too_low(n, a, b, mid)) lo = mid;
        else hi = mid;
    }

    ld ans = get_dp1(n, a, b, lo);
    cout << fixed << setprecision(6) << ans << '\n';
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now(); 
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}