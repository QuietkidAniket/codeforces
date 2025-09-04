/**
 *    author: Anicetus_7
 *    created: 2025-06-23 21:47:44
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define PI (double)(3.14159265358979)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


int n;
vector<vector<int>> adjl(200001);
vector<pair<int,int>> ans;

void dfs(int node, int p, int par){
  for(int adjnode : adjl[node]){
    if(adjnode == par)continue;
    if(p ==1){
      cout << node <<  " "<< adjnode << '\n';
    }else{
      cout << adjnode << " " << node << '\n';
    }
    dfs(adjnode, 1-p, node);
  }
}


void Solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    adjl[i].clear();
  }
  ans.clear();


  for(int i = 0; i < n - 1; i++) {
    int u, v;
     cin >> u >> v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }

  int node  = -1;
  for(int i = 1; i <= n; i++){
    if(adjl[i].size() ==2){
      node = i;
      break;
    }
  }
  if(node == -1){
    cout << "NO" << '\n';
  }else{
    cout << "YES" << '\n';
    cout << node << " " << adjl[node][0] << '\n';
    cout << adjl[node][1] << " " << node << '\n';
    dfs(adjl[node][0], 0, node);
    dfs(adjl[node][1], 1, node);
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}