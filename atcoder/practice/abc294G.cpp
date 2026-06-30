/**
 *    author: Anicetus_7
 *    created: 2026-06-30 14:50:18
**/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#else
#define DEBUG(x) 42 
#endif
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n;cin>>n;

  vector<vector<pair<int,int>>> adj(n+1);

  for(int i =0; i <n-1;i++){
    int u,v,w; cin>>u>>v>>w;

    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  vector<vector<int>> anc(n+1, vector<int>(25, 0));
  vector<int> euler_path;
  vector<int> sz(n+1,0);
  function<void(int,int)> dfs = [&](int nd, int par){
    euler_path.push_back(nd);
    sz[nd] = 1;
    for(int ad : adj[nd]){
      if(ad == par)continue;
      dfs(ad, nd);
      sz[nd] += sz[ad];
    }
    anc[nd][0] = par;
    for(int bit = 1; bit < 25; bit++){
      anc[nd][bit] = lca[lca[nd][bit-1]][bit-1];
    }
  };

  int q; cin>>q;
  for(int i =0; i <q ; i++){
    int c; cin>>c;
    if(c== 1){
      int nd, w; cin>>nd>>w;
    }else{
      int u,c; cin>>u>>v;

    }
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
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