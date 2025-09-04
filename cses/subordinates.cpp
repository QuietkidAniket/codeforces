/**
 *    author: Anicetus_7
 *    created: 2025-06-27 19:46:23
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


vector<int> dp(2*1e5);
vector<vector<int>> child(2*1e5);

int dfs(int node){
  int sum =0;
  for(int adjnode : child[node]){
    sum += dfs(adjnode);
  }
  dp[node] = sum;
  return sum+1;
}

void Solve(){ 
  int n; cin>> n;
  dp.assign(n+1,  0);
  for(int i = 1; i <= n; i++)child[i].clear();

  for(int i =2; i <= n; i++){
    int x; cin>> x;
    child[x].push_back(i);
  }

  dfs(1); 
  for(int i = 1; i <= n; i++){
    cout << dp[i] << " ";
  }
  cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}