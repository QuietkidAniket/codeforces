/**
 *    author: Anicetus_7
 *    created: 2025-10-28 13:28:12
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
  for(int i =0 ;i < n-1; i++){
    int u,v ; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n+1, 0);
  vector<int> depth(n+1,0), mxdepth(n+1, 0);
  function<void(int)> dfs = [&](int node) -> void{
      vis[node] = 1;
      mxdepth[node] = depth[node];
      for(int adjnode : adj[node]){
          if(vis[adjnode])continue;
          depth[adjnode] = depth[node]+1;
          dfs(adjnode);
          mxdepth[node] = max(mxdepth[node], mxdepth[adjnode]);
      }
  };
  dfs(1);
  int ans = 0;
  vector<int> diff(mxdepth[1] +2, 0);
  for(int node =1; node <= n; node++)diff[depth[node]]++, diff[mxdepth[node]+1]--;
  for(int d =1; d <= mxdepth[1]; d++)diff[d]+= diff[d-1];
  int best_depth = max_element(diff.begin(), diff.end()) - diff.begin();
  for(int node =1; node <= n; node++){
      if(depth[node] <= best_depth && mxdepth[node] >= best_depth)continue;
      else ans++;
  }

  cout <<ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++)
    {
        cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
