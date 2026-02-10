/**
 *    author: Anicetus_7
 *    created: 2025-12-22 21:48:10
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
  vector<vector<int>> adjl(n+1);
  for(int i =0 ;i < n-1; i++){
    int u, v; cin>>u>>v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }
  if(n&1){
    cout << "-1\n";
    return;
  }
  vector<int> dp(n+1,0);
  int ans =0;
  function<int(int,int)> dfs = [&](int node, int par)->int{
    dp[node] = 1;
    for(int adjnode:  adjl[node]){
      if(adjnode == par)continue;
      dp[node] += dfs(adjnode, node);
    }
    if(node !=1 && dp[node]%2==0)ans++;
    return dp[node];
  };
  dfs(1,-1);
  cout <<ans<<endl;
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