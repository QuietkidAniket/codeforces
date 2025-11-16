/**
 *    author: Anicetus_7
 *    created: 2025-10-16 13:18:26
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n; cin>>n;
  int degree[n+1];
  memset(degree,0, sizeof degree);

  vector<vector<int>> adjl(n+1);
  for(int i =0 ; i < n ;i++){
    int u,v; cin>>u>>v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }
  // all degrees should be 2
  for(int node =1; node <= n; node++){
    if(degree[node] != 2){
      cout << "NO" <<endl;
      return;
    }
  }

  // check for bipartiteness by bi-coloring
  vector<int> color(n+1,-1);

  function<bool(int, int)> dfs= [&](int node, int col)->bool{
    color[node] = col;
    for(auto adjnode: adjl[node]){
      if(color[node] == color[adjnode])return false;
      if(color[adjnode] == -1){
        if(!dfs(adjnode, 1-col))return false;
      }else if(color[adjnode]== color[node]){
        return false;
      }
    }
    return true;
  };

  for(int node =1; node <= n; node++){
    if(color[node] == -1){
      if(!dfs(node, 0)){
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
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