/*
 * author: Anicetus_7
 * created: 2026-01-31 09:37:26
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
    for(int i =0 ; i < n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<double> res(n+1,1), depth(n+1,0);
    vector<bool> vis(n+1,false);
    double ans = 0.00;
    function<void(int)> f  = [&](int node)->void{
        vis[node] = true;
        int cnt =0;
        for(int adjnode : adj[node]){
            if(vis[adjnode])continue;
            cnt++;
        }
        for(int adjnode : adj[node]){
            if(vis[adjnode])continue;
            depth[adjnode] = depth[node]+1;
            res[adjnode] = res[node]*cnt;
            f(adjnode);
        }
        if(!cnt){
            ans += (double)depth[node]/res[node];
        }
    };
    f(1);
    // cout << "hihi\n";
    cout << fixed << setprecision(15) << ans <<endl;
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin >> t;
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
