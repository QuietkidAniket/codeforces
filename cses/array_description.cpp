/**
 *    author: Anicetus_7
 *    created: 2025-09-05 14:39:32
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  int m; cin>>m;
  vector<int> a(n);
  for(auto& x : a)cin>> x;

  if(n == 1){
    if(a[0] == 0){
      cout << m << endl;
    }else{
      cout << 1 << endl;
    }
    return;
  }

  vector<vector<int>> dp(n, vector<int>(m+1,0));

  if(a[0] == 0){
    for(int i =1; i <=m; i++){
      dp[0][i] = 1; 
    }
  }else{
    // for(int i = max(a[0]-1, 1ll);i <= min(a[0]+1, m);i++){ 
      dp[0][a[0]] = 1;
    // }
  }
  
  for(int i = 1; i <n; i++){
    if(a[i] == 0){
      for(int x= 1; x <= m; x++){
        dp[i][x] = dp[i-1][x];
        if(x-1 >=1)dp[i][x] = (dp[i][x] + dp[i-1][x-1])%MOD;
        if(x+1 <=m)dp[i][x] = (dp[i][x] + dp[i-1][x+1])%MOD;
      }
    }else{
      int x=  a[i];
      dp[i][x] = dp[i-1][x];
      if(x-1 >=1)dp[i][x] = (dp[i][x] + dp[i-1][x-1])%MOD;
      if(x+1 <=m)dp[i][x] = (dp[i][x] + dp[i-1][x+1])%MOD;
    }
  }


  cout << accumulate(dp[n-1].begin(), dp[n-1].end(), 0ll)%MOD << endl;

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