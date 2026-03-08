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
    int m; cin>>m;
    for(int i =0 ;i < m; i++){
        int u,v; cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bitset<1000> vis;
    vis.reset();
    // bitset<1000> on_stack;
    // on_stack.reset();
    function<bool(int)> dfs =[&](int node){
        vis[node] =1;
        for(int adjnode: adj[node]){
            if(!vis[adjnode])dfs(adjnode);
            else return true;
        }
        return false;
    };
    int n_cycles = 0;
    // read input, etc
    for(int s = 1; s < (1<<n); s++){
        vis.reset();
        vis |= s;
        vis.flip();
        for(int node =0; node < n; node++){
            if(!vis[node]){
                if(dfs(node))n_cycles++;       
                break;
            }
        }
    }
	cout << n_cycles << endl;

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
