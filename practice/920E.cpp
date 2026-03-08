/**
 *    author: Anicetus_7
 **/
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
  int n,m; cin>>n>>m;
  vector<unordered_set<int>> a(n + 1);
  for (int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    a[u].insert(v);
    a[v].insert(u);
  }
  set<int> unvisited;
  for(int node = 1; node<= n; node++)unvisited.insert(node);
  
  int cnt=0;
  vector<int> sz;
  function<void(int)> dfs = [&](int node) {
    sz[cnt]++;
    auto it = unvisited.begin();
    while(it!= unvisited.end()){
        int adjnode = *it;
        if(!a[node].count(adjnode)){
            unvisited.erase(it);
            dfs(adjnode);
            it = unvisited.upper_bound(adjnode);
        }else it++;
    }
  };
  for (int node = 1; node <= n; node++) {
    auto it = unvisited.find(node);
    if(it != unvisited.end()){
        sz.push_back(0);
        unvisited.erase(it);
        dfs(node);
        cnt++;
    }
  }
  cout << cnt<< endl;
  sort(sz.begin(), sz.end());
  for(int cs : sz)cout <<cs << " ";
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
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
