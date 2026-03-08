/**
 *    author: Anicetus_7
 *    created: 2026-02-01 15:04:36
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,m; cin>>n>>m;
  vector<vector<int>> adj(n+1);
  for(int i = 0 ;i < m; i++){
    int u, v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n+1,0);
  function<void(int)> dfs = [&](int node){
    vis[node] = 1;
    for(int adjnode : adj[node]){
      if(vis[adjnode])continue;
      dfs(adjnode);
    }
  };
  vector<int> p(n, 0);
  for(int i =0; i<n ;i++)cin>> p[i];
  set<int> excluded;
  for(int i = 0; i <n; i++){
    vis.assign(n+1,0);
    int cnt =0;
    bool flag = false;
    for(int node = 1; node <= n; node++){
      if(excluded.count(node))continue;
      if(!vis[node])cnt++;
      if(cnt>1){
        flag= true;
        break;
      }
      dfs(node);
    }
    if(flag)cout << "NO\n";
    else cout << "YES\n";
    adj[p[i]].clear();
    excluded.insert(p[i]);
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  freopen("closing.in", "r+", stdin);
  freopen("closing.out", "w+", stdout);
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