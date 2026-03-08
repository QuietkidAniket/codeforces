/**
 *    author: Anicetus_7
 *    created: 2026-02-03 00:10:22
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  auto diameter = [](int n){
    vector<vector<int>> adj(n+1);
    for(int i = 0;i< n-1; i++){
      int u, v; cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<int> d1(n+1, 0), d2(n+1,0), vis(n+1,0);
    function<void(int, vector<int>&)> dfs=  [&](int node, vector<int>& depth){
      vis[node] = 1;
      for(int adjnode: adj[node]){
        if(vis[adjnode])continue;
        depth[adjnode] = depth[node] + 1;
        dfs(adjnode, depth);
      }
    };
    dfs(1, d1);
    int idx1 = max_element(d1.begin()+1, d1.end())- d1.begin();

    vis.assign(n+1, 0);
    dfs(idx1, d2);
    int diam = *max_element(d2.begin()+1, d2.end());
    return diam;
  };
  int n; cin>>n;  
  int diameter1 = diameter(n);
  int m; cin>>m;
  int diameter2 = diameter(m);
  int mx = max(diameter1, diameter2);
  cout << max((diameter1+1)/2 + (diameter2+1)/2 +1 ,mx)<<endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}