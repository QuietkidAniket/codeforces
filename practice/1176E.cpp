/**
 *    author: Anicetus_7
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    int n, m;cin >> n>>m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> colour(n + 1, -1);
    vector<vector<int>> cnt(2);
    function<void(int, int)> dfs = [&](int node, int col) {
        colour[node] = col;
        cnt[col].push_back(node);
        for (int adjnode : adj[node]) {
            if (colour[adjnode] != -1) continue;
            dfs(adjnode, 1 - col);
        }
    };
    dfs(1, 0);
    if(cnt[0].size() <= n/2){
        cout << cnt[0].size() << endl;
        for(int x: cnt[0])cout << x <<" ";
        cout << endl;
    }else{
        cout << cnt[1].size() << endl;
        for(int x: cnt[1])cout << x <<" ";
        cout << endl;
    }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": \n";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
