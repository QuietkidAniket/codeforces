/**
 * author: Anicetus_7
 * created: 2026-01-21 19:17:46
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n,m; cin>>n>>m; 
    vector<vector<int>> adj(n+1);  
    vector<vector<int>> adjrev(n+1);
    for(int i = 0 ;i < m; i++){
       int u, v; cin>>u>>v;
       adj[u].push_back(v);
       adjrev[v].push_back(u);

    }
    /*
     * Kosaraju's Algorithm
     */
    stack<int> stk; // for storing the topo sort
    vector<bool> vis(n+1, false);
    function<void(int)> dfs = [&](int node) -> void{
        vis[node] = true;
        for(int adjnode: adj[node]){ 
            if(!vis[adjnode]){
                dfs(adjnode);
            }
        }
        stk.push(node);
    };
    function<void(int)> dfs2 = [&](int node) -> void{
        vis[node] = true;
        for(int adjnode: adjrev[node]){ 
            if(!vis[adjnode]){
                dfs2(adjnode);
            }
        }
    };
    
    for(int node =1; node<= n; node++){
        if(!vis[node]){
            dfs(node);
        }
    }

    vector<int> ans;
    vis.assign(n+1,false);
   // dfs on the reverse
    while(!stk.empty()){
        int node= stk.top();
        stk.pop();
        if(!vis[node]){
            ans.push_back(node);
            dfs2(node);
        }
        if(ans.size()== 2)break;
    }
    if(ans.size() > 1){
        cout << "NO\n";
        // print("{} {}", ans[0], ans[1]);
        cout << ans[1] << " " << ans[0] <<endl;
    }else cout << "YES\n";
    
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin >> t;
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

