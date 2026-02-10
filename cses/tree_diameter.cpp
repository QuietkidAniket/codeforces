/**
 *    author: Anicetus_7
 *    created: 2026-01-31 11:29:19
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<vector<int>> adj(n+1);
  for(int i = 0;i< n -1; i++){
    int u, v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<bool> vis(n+1, false);
  vector<int> d1(n+1, 0);
  vector<int> d2(n+1, 0);
  vector<int> d3(n+1, 0);
  function<void(int, vector<int>&)> dfs = [&](int node, vector<int>& depth)->void{
    vis[node] = true;
    for(int adjnode : adj[node]){
      if(vis[adjnode]) continue;
      depth[adjnode] =  depth[node] +1;
      dfs(adjnode, depth);
    }
  };

  dfs(1,d1);
  int idx1 = max_element(d1.begin(), d1.end())-d1.begin();

  vis.assign(n+1,false);
  dfs(idx1,d2);
  int idx2 = max_element(d2.begin(), d2.end())- d2.begin();
  int ans = d2[idx2];
  // for(int i = 1; i <= n; i++){
  //   ans = max(ans, d1[i] + d2[i]-1);
  // }
  cout << ans << endl;
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