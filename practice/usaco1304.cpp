/**
 *    author: Anicetus_7
 *    created: 2026-02-04 22:29:56
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct Flight{
  int no;
  int start; 
  int end;
  Flight(int n, int s, int e): no(n), start(s), end(e) {}
  // Flight(Flight&& f): no(f.no), start(f.start), end(f.end) {}
};

void Solve(){
  int n,m; cin>>n>>m;
  vector<vector<Flight>> adj(n+1);
  for(int i=0 ;i <m; i++){
    int u,start,v,end; cin>>u>>start>>v>>end;
    adj[u].push_back(Flight{v,start,end});
  }
  for(int i =1;i <=n; i++){
    sort(adj[i].begin(), adj[i].end(), [](const Flight& a, const Flight& b){
      return a.start > b.start;
    });
  }
  vector<int> a(n+1, 0);
  for(int i =1;i <=n; i++)cin>>a[i];
  vector<int> dist(n+1, INF);
  queue<pair<int,int>> q;
  pq.push({0, 1});
  dist[1] = 0;
  while(!q.empty()){
    auto [e,node] = q.front();
    pq.pop();
    if(e > dist[node])continue;
    for(auto& adjnode : adj[node]){
      if(e + (node==1? 0:a[node])> adjnode.start)break;
      if(dist[adjnode.no] > adjnode.end){
        dist[adjnode.no] = adjnode.end;
        pq.push({adjnode.end, adjnode.no});
      }
    }
  }
  for(int node = 1; node<=n; node++)cout << (dist[node]==INF? -1:dist[node]) << '\n';

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