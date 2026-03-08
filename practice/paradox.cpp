/**
 *    author: Anicetus_7
 *    created: 2026-01-14 13:48:18
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

bool Solve(){
  int n; cin>>n;
  if(!n)return true;

  vector<vector<int>> adj(n+1);
  vector<int> colour(n+1,-1);
  bool flag = true;
  for(int u= 1; u<= n; u++){
    int v; string col; cin>>v>>col;
    adj[u].push_back(v);

    if(col == "true"){
      if(colour[v] == 0 || colour[u] == 0)flag = false;
      colour[u] = 1;
      colour[v] = 1;
    }else{
      if(colour[v] == 1 || colour[u] == 1)flag = false;
      colour[u] = 0;
      colour[v] = 0;
    }
  }
  if(!flag){
    cout << "PARADOX\n";
    return false;
  }
    
  vector<int> vis(n+1,0);
  
  function<bool(int)> dfs = [&](int node)-> bool{
    vis[node] = 1;
    if(adj[node].size()==0)return true;
    int adjnode =  adj[node][0];
    if(colour[adjnode] != colour[node])return false;
    if(!vis[adjnode]){
      return dfs(adjnode);
    }else return true;
  };
  
  for(int node = 1; node <= n; node++){
    if(!vis[node]){
      flag &= dfs(node);
      if(!flag)break;
    }
  }
  if(!flag)cout << "PARADOX\n";
  else cout << "NOT PARADOX\n";
  return false;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  while(true)
  {
      // cout << "Case #" << n << ": \n";
      if(Solve())break;
  }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}