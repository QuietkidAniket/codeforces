/**
 *    author: Anicetus_7
 *    created: 2026-02-02 00:09:38
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, m; cin>>n>>m;
  vector<int> a(n);
  for(auto& x : a)cin>> x;

  vector<vector<pair<int,int>>> adj(n+1);
  for(int i = 0 ;i < m; i++){
    int u, v, w; cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  vector<int> oo;
  for(int i = 0;i  <n; i++){
    if(i+1 != a[i])oo.push_back(i+1);
  }
  if(oo.empty()){
    cout << -1<<endl;
    return ;
  }
  auto check = [&](int target){ // target is the minimum edge weight
    vector<int> comp(n+1,-1);
    function<void(int,int)> dfs = [&](int node, int cid){
      comp[node] = cid;
      for(auto& [adjnode, w]: adj[node]){
        if(comp[adjnode] != -1)continue;
        if(w < target)continue;
        dfs(adjnode, cid);
      }
    };
    int cid =0;
    for(int node = 1; node <=n; node++){
      if(comp[node] == -1)dfs(node, cid++);
    }
    for(int i = 1; i <=n; i++){
      if(a[i-1] != i){
        if(comp[i] != comp[a[i-1]]) return false;
      }
    }
    return true;
  };

  int l = 0, h= 1e9;
  while(l <=h ){
    int mid = (l+h)>>1;
    if(check(mid)){ // maximize the minimum edge weight
      l = mid +1;
    }else h = mid -1;
  }
  cout << h << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
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