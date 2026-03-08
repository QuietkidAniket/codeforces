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
    vector<vector<int>> adj(n+1);
    for(int i = 0; i <m; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> outpar(n+1,0), timer(n+1,-1), vis(n+1,0);
    vector<pair<int,int>> edges; //{u,v} = u -> v
    if(m&1){
        cout << "IMPOSSIBLE\n";
        return;
    }
    int t = 0;
    auto dfs = [&](auto&& f, int node, int par)->void{
        vis[node]  = 1;
        timer[node] = t++;
        for(int adjnode: adj[node]){
            if(adjnode == par)continue;
            if(vis[adjnode]){
                if(timer[adjnode] < timer[node]){
                    edges.push_back({node, adjnode});
                    outpar[node] ^= 1;
                }
            }else{
                f(f, adjnode, node);
                if(outpar[adjnode]){
                    edges.push_back({adjnode, node});
                    outpar[adjnode] ^= 1;
                }else{
                    edges.push_back({node, adjnode});
                    outpar[node] ^= 1;
                }
            }
        }
    };
    for(int node =1; node<=n; node++){
        if(timer[node] == -1)dfs(dfs,node, -1);
    }
    for(int d : outpar)if(d&1){cout<< "IMPOSSIBLE\n"; return;}
    for(auto& [u, v] : edges)cout <<u <<" " <<v <<endl;
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
