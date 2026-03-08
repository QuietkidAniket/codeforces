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
    int n;cin>>n;
    int m;cin>>m;
    vector<int> indegree(n+1, 0);
    vector<vector<int>> adj(n+1);
    vector<vector<int>> back_edge(n+1);
    for(int i=0; i < m; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        back_edge[v].push_back(u);
        indegree[v]++;
    }

    vector<int> topo;
    queue<int> q;
    for(int node =1 ;node <= n; node++){
        if(!indegree[node])q.push(node);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(int adjnode : adj[node]){
            indegree[adjnode]--;
            if(indegree[adjnode] == 0){
                q.push(adjnode);
            }
        }
    }
    // assert(topo.front() == 1);
    
    vector<int> dist(n+1, -INF);
    vector<int> par(n+1, 0);
    dist[1] = 0;
    for(int node: topo){
        for(int prev: back_edge[node]){
            if(dist[prev] != -INF && dist[prev] + 1 > dist[node]){
                dist[node] = dist[prev] + 1;
                par[node] = prev;
            }
        }
    }

    if(dist[n] < 0){
        cout <<"IMPOSSIBLE\n";
    }else{
        cout << dist[n]+1 << endl;
        vector<int> route;

        int cur = n;
        while(cur != 0){
            route.push_back(cur);
            cur = par[cur];
        }
        reverse(route.begin(), route.end());
        for(int x : route) cout << x << " ";
    }


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
