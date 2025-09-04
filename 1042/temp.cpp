/**
 *    author: Anicetus_7
 *    created: 2025-08-20
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int editDistance(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = i; // deletions
    for(int j = 0; j <= m; j++) dp[0][j] = j; // insertions

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int cost = (s1[i-1] == s2[j-1] ? 0 : 2);
            dp[i][j] = min({
                dp[i-1][j] + 1,       // delete
                dp[i][j-1] + 1,       // insert
                dp[i-1][j-1] + cost   // substitute / match
            });
        }
    }
    return dp[n][m];
}

void Solve(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << editDistance(s1, s2) << "\n";
}

//|------------------------------------------[MAIN]------------------------------------------|
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