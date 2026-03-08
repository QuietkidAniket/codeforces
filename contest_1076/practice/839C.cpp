/**
 *    author: Anicetus_7
 *    created: 2026-01-26 08:30:09
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

  for(int i =0 ; i <n-1; i++){
    int u, v; cin>>u>>v;
    adj[u].push_back(v);
  }
  // find the depths
  vector<int> depth(n+1,0);
  // also find the number of leaves
  double n_leaves = 0;
  function<void(int,int)> dfs = [&](int node, int par)-> void{
    depth[node] = depth[par] + 1;
    if(!(int)adj[node].size())n_leaves++;
    for(int adjnode: adj[node]){
      if(adjnode == par)continue;
      dfs(adjnode, node);
    }
  };
  depth[0] = -1;
  dfs(1, 0);
  
  // calculate the expectation of the depths
  
  vector<int> freq(n+1,0);
  for(int i = 1;i<= n; i++){
    if(!(int)adj[i].size())freq[depth[i]]++;
  }
  double expectation = 0;
  for(double d = 1; d <= n; d++){
    expectation += d*(freq[d]/n_leaves);
  }
  cout << fixed << setprecision(6) << expectation << endl;

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