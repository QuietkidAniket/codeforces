/**
 *    author: Anicetus_7
 *    created: 2025-10-23 15:58:31
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
  vector<vector<int>> adjl(n+1);
  for(int i= 0; i<m; i++){
    int u, v; cin>>u>>v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }
  int x = -1,y = -1;
  function<void(int,int)> dfs = [&](int node, int par)->void{
    if(adjl[node].size() > 1){
      if(y == -1){
        y = adjl[node].size()-1;
      }else{ 
        x = adjl[node].size();
        return;
      }
    }
    for(int adjnode : adjl[node]){
      if(adjl[adjnode].size() > 1 && adjnode != par){
        dfs(adjnode, node);
        break;
      }
    }
  };

  for(int i = 1; i <=n ; i++){
    if(adjl[i].size() == 1){
      dfs(i, -1);
      break;
    }
  }
  cout << x << " "<<y<<endl;
  
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