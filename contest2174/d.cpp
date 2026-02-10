/**
 * author: Anicetus_7
 * created: 2025-12-06 15:36:00
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> pos[365];
vector<pair<int,int>> dp[365][365];

void Solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);

    for(int i = 0; i <= k; i++){
        pos[i].clear();
        for(int j = 0; j <= k; j++) dp[i][j].clear();
    }

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int v = 1; v <= min<int>(a[i], k); v++) pos[v].push_back(i);
    }

    dp[0][0].push_back({0, 0});
    int max_happiness = 0;

    for(int c = 0; c <= k; c++){
        for(int u = 0; u <= c; u++){
            if(dp[c][u].empty()) continue;

            sort(dp[c][u].begin(), dp[c][u].end());
            vector<pair<int,int>> clean;
            int min_pen = INF;
            for(auto &p : dp[c][u]){
                if(p.second < min_pen){
                    clean.push_back(p);
                    min_pen = p.second;
                }
            }
            dp[c][u].swap(clean);

            for(auto &p : dp[c][u]){
                int pen = p.second;
                int h = (n + 1) * u - pen;
                max_happiness = max(max_happiness, h);
            }

            for(int v = u + 1; c + v <= k; v++){
                int next_cost = c + v;
                if(pos[v].empty()) continue;
                for(auto &p : dp[c][u]){
                    int prev_idx = p.first;
                    int prev_pen = p.second;
                    auto it = upper_bound(pos[v].begin(), pos[v].end(), prev_idx);
                    if(it == pos[v].end()) continue;
                    int next_idx = *it;
                    int added_pen = next_idx * (v - u);
                    dp[next_cost][v].push_back({next_idx, prev_pen + added_pen});
                }
            }
        }
    }

    cout << max_happiness << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) Solve();
    return 0;
}