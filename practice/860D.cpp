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
    int n,m; cin>>n>>m;
    vector<set<int>> adj(n+1);
    for(int i =0 ;i <m;i++){
        int u, v; cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    vector<int> used(n+1,0), vis(n+1,0), par(n+1,0);
    
    vector<array<int,3>> ans;
    auto dfs = [&](auto&& f, int node)->void{
        vis[node] =1;
        vector<int> gone, reachable;
        for(int adjnode: adj[node]){
            if(!vis[adjnode]){
                par[adjnode] = node;
                f(f, adjnode);
                gone.push_back(adjnode);
            }
        }
        for(int adjnode: adj[node]){
            if(!used[adjnode]&& par[node] != adjnode){
                reachable.push_back(adjnode);
            }
        }
        if((int)reachable.size()%2 == 1){
            if(par[node] != 0)reachable.push_back(par[node]);
            for(int i=0; i +1<reachable.size(); i+=2){
                ans.push_back({reachable[i], node, reachable[i+1]});
            }
            used[node] = 1;
            for(int x: gone)used[x] = 1; // mark those in the tree which are reachable
        }else{
            for(int i=0; i +1<reachable.size(); i+=2){
                ans.push_back({reachable[i], node, reachable[i+1]});
            }
            for(int x: gone)used[x] = 1; // mark those in the tree and are reachable
        }
    };
    for(int node = 1; node<=n; node++)if(!vis[node])dfs(dfs, node);
    cout <<ans.size() <<endl;
    for(auto& vec: ans)cout << vec[0] <<" " << vec[1] <<" " <<vec[2] <<endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
