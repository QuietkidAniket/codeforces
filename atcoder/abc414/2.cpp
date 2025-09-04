/**
 *    author: Anicetus_7
 *    created: 2025-07-13
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)

void Solve() {
    int n;                       
    if(!(cin >> n)) return;
    vector<vector<int>> adj(n);  

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x; cin >> x;
            if(x) adj[i].push_back(j);
        }
    }

    // ---- Tarjan articulation-point algorithm ----
    vector<int> disc(n, -1), low(n, -1), parent(n, -1);
    vector<char> isArt(n, 0);
    int timer = 0;

    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = timer++;
        int children = 0;
        for(int v : adj[u]) {
            if(disc[v] == -1) {                  
                parent[v] = u;
                ++children;
                dfs(v);
                low[u] = min(low[u], low[v]);

                // articulation conditions
                if(parent[u] == -1 && children > 1) isArt[u] = 1;
                if(parent[u] != -1 && low[v] >= disc[u]) isArt[u] = 1;
            }
            else if(v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    };

    for(int i = 0; i < n; ++i)
        if(disc[i] == -1) dfs(i);

    // ---- Collect Type B cities ----
    vector<char> isB(n, 0);
    for(int u = 0; u < n; ++u)
        if(isArt[u])
            for(int v : adj[u])
                if(!isArt[v]) isB[v] = 1;

    // ---- Output ----
    bool first = true;
    for(int i = 0; i < n; ++i)
        if(isB[i]) {
            if(!first) cout << ' ';
            cout << i;
            first = false;
        }
    cout << '\n';
}

