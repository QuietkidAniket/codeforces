/**
 *    author: Anicetus_7
 *    created: 2025-12-06 17:54:06
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, m; cin>>n>>m;

  vector<vector<int>> adjl(n+1);


  int reach[n+1];
  memset(reach, 0, sizeof reach);
  
  for(int i = 0;i < m; i++){
    int u,v; cin>>u>>v;
    adjl[v].push_back(u);
  } 

  function<void(int)> dfs = [&](int node) -> void{
    reach[node] = 1;
    for(int adjnode: adjl[node]){
      if(reach[adjnode])continue;
      dfs(adjnode);
    }
  };

  int q; cin>>q;
  for(int i =0;i < q; i++){
    int c; cin>>c;
    int node; cin>>node;
    if(c == 1){
      if(reach[node])continue;
      dfs(node);
    }else{
      if(reach[node])cout << "Yes\n";
      else cout << "No\n";
    }
  }

  
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