/**
 *    author: Anicetus_7
 *    created: 2025-11-17 14:54:49
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
#define pii pair<int,int>
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  int m; cin>>m;
  vector<pii> adjl[n+1]; // node, weight
  for(int i =0 ;i < m; i++){
    int u,v;  string edge; cin>>u>>v>>edge;
    int w = edge=="imposter" ? 1 : 0;
    adjl[u].push_back(pii(v, w));
    adjl[v].push_back(pii(u, w));
  }
  vector<int> colour(n+1, -1);
  int c[2]; 
  function<bool(int,int)> dfs = [&](int node, int col) -> bool{
    colour[node] = col;
    c[colour[node]]++;
    for(const auto& [adjnode, w] : adjl[node] ){
      if(colour[adjnode] == -1){
        colour[adjnode]  = colour[node] ^ w;
        if(!dfs(adjnode, colour[adjnode]))return false;
      }else{
        if(colour[adjnode] != (colour[node] ^ w))return false;
      }
    }
    return true;
  };
  int ans =0;
  bool flag = false;
  for(int i =1; i <=n ;i++){
    if(colour[i] ==-1){
      c[0] = c[1] = 0;
      if(!dfs(i, 0)){
        flag = true;
        break;
      }
      ans += max(c[0], c[1]);
    }
  }

  if(flag){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
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