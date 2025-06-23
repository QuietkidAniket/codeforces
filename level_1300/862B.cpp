/**
 *    author: Anicetus_7
 *    created: 2025-06-21 01:32:10
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define MAX (int)(1e5+1)

int n;
vector<vector<int>> adjl(MAX);
vector<int> vis(MAX);
int color[2];

void dfs(int node, int prev_color){
  vis[node] = 1;
  color[prev_color]++;
  for(int adjnode : adjl[node]){
    if(!vis[adjnode]){
      dfs(adjnode, 1- prev_color);
    }
  }
}

void Solve(){
  cin>> n;
  adjl.assign(n+1, vector<int>(0));
  vis.assign(n+1, 0);
  memset(color, 0 , sizeof color);

  for(int i = 0; i < n-1; i++){
    int u,v; cin>> u>>v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }

  dfs(1,0);

  cout <<  color[0]*color[1] - (n-1) <<'\n';
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}