/**
 *    author: Anicetus_7
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
    for(int i =0 ;i < n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp1(n+1,vector<int>(2, 0)); //for dp1[node][], 0-> sum of paths, 1-> subtree size
    vector<int> dp2(n+1,0);
    vector<int> vis(n+1, 0);
    function<void(int)> dfs = [&](int node){
        vis[node]= true;
        dp1[node][1] = 1;
        for(int adjnode : adj[node]){
            if(vis[adjnode])continue;
            dfs(adjnode);
            dp1[node][1] += dp1[adjnode][1];
            dp1[node][0] += dp1[adjnode][0] + dp1[adjnode][1];
        }
    };
    dfs(1);
    dp2[1] = dp1[1][0];
    function<void(int, int)> dfs2 = [&](int node, int par){
        if(node != 1)dp2[node] = dp2[par]- (dp1[node][1] + dp1[node][0]) +  (n- dp1[node][1]) +  dp1[node][0];
        for(int adjnode : adj[node]){
            if(par== adjnode)continue;
            dfs2(adjnode, node);
        }
    };
    dfs2(1, -1);
    for(int node = 1; node <=n ;node++){
        cout << dp2[node] << " ";
    }
    cout <<'\n';
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
