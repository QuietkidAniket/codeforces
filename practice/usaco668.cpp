/**
 *    author: Anicetus_7
 *    created: 2026-02-01 19:17:27
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
  int a[n][3];
  for(int i  =0;i < n; i++){
    int x, y, p; cin>>x>>y>>p;
    a[i][0] = x;
    a[i][1] = y;
    a[i][2] = p;
  }
  auto dist = [&](int* p, int* q){
    return (p[0]- q[0])*(p[0]-q[0]) + (p[1] -q[1])*(p[1]-q[1]);
  };
  vector<int> vis(n,0);
  function<int(int)> dfs = [&](int node)->int {
    vis[node] = 1;
    int cnt = 0;
    for(int j =0 ; j <n ;j++){
      if(dist(a[node], a[j]) <= a[node][2]*a[node][2] && !vis[j]){
        cnt += dfs(j);
      }
    }
    return cnt + 1;
  };
  int ans =0;
  for(int i =0;i < n; i++){
    if(!vis[i]){
      vis.assign(n,0);
      ans = max(ans, dfs(i));
    }
  }
  cout << ans <<endl; 
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
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