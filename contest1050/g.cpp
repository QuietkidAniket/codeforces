/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define vec vector
int countStable(vector<int>& a){
    int n = a.size();
    
    vec<vec<vec<int>>> dp(n + 1, vec<vec<int>>(2, vec<int>(3, 0)));

    for(int i = 0; i < n; i++){
        int cur = (a[i]& 1);
        dp[i + 1][cur][1] = (dp[i + 1][cur][1] + 1) % MOD;
        int prev = 0;
        for(; prev < 2; prev++){
            for(int k = 1; k <= 2; k++){
                if(!dp[i][prev][k]) continue;
                dp[i + 1][prev][k] = (dp[i + 1][prev][k] + dp[i][prev][k]) % MOD;
                if(prev == cur){
                    if(k + 1 <= 2) dp[i + 1][prev][k + 1] = (dp[i + 1][prev][k + 1] + dp[i][prev][k]) % MOD;
                } else {
                    dp[i + 1][cur][1] = (dp[i + 1][cur][1] + dp[i][prev][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int p = 0; p < 2; p++){
      for(int k = 1; k <= 2; k++) ans = (ans + dp[n][p][k]) % MOD;
    }
    return ans;
}

void Solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << countStable(a) << "\n";
}

int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; i++) Solve();
    auto end = std::chrono::high_resolution_clock::now(); 
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}

