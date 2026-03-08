/**
 *    author: Anicetus_7
 *    created: 2026-02-01 23:46:21
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
  int m; cin>>m;
  vector<vector<int>> coord(n+1, vector<int>(2));
  for(int i = 1; i <=n; i++){
    cin>>coord[i][0]>>coord[i][1];
  }

  vector<vector<int>> adj(n+1);
  for(int i = 0; i <m; i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int mxx=0, mnx =INF,mny = INF, mxy = 0;
  vector<int> vis(n+1,0);
  function<void(int)> dfs = [&](int node){
    vis[node] = 1;
    mxx = max(mxx, coord[node][0]);
    mnx = min(mnx, coord[node][0]);
    mxy = max(mxy, coord[node][1]);
    mny = min(mny, coord[node][1]);
    for(int adjnode : adj[node]){
      if(vis[adjnode])continue;
      dfs(adjnode);
    }
  };
  int ans = INF;
  for(int i = 1;i <= n; i++){
    if(!vis[i]){
      mxx=0, mnx =INF,mny = INF, mxy = 0;
      dfs(i);
      ans= min(ans, 2*(mxx-mnx +  mxy-mny));
    }
  }
  cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);
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