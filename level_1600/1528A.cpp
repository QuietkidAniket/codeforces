/**
 *    author: Anicetus_7
 *    created: 2025-10-23 09:50:56
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
  vector<pair<int,int>> rng(n+1);
  for(int i =1;i <= n; i++){
    cin>>rng[i].first>>rng[i].second;
  }
  for(int i =1;i <= n-1; i++){
    int u,v;cin>>u>>v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }
  
  vector<vector<int>> dp(n+1, vector<int>(2,0)); // dp[i][0]->max sum if lowest value, dp[i][1]->max sum if highest value
  vector<int32_t> vis(n+1,0);

  function<void(int,int)> dfs = [&](int node, int par) -> void{
    vis[node] = 1;
    int sum = 0;
    const auto& [lu,hu] = rng[node];
    int sum1 = 0, sum2 = 0;
    for(int adjnode: adjl[node]){
      const auto& [lv, hv] = rng[adjnode];
      if(adjnode == par)continue;
      if(vis[adjnode])continue;
      dfs(adjnode, node); 
      dp[node][0] += max(dp[adjnode][1] + abs(lu - hv), dp[adjnode][0] + abs(lu - lv));
      dp[node][1] += max(dp[adjnode][1] + abs(hu - hv), dp[adjnode][0] + abs(hu - lv));
    }
  };

  int ans = 0;
  for(int node =1; node<= n; node++){
    if(!vis[node]){
      dfs(node, -1);
      ans = max(ans, max(dp[node][0], dp[node][1]) );
    }
  }

  cout << ans << endl;
  
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