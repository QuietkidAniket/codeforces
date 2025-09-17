/**
 *    author: Anicetus_7
 *    created: 2025-09-15 20:36:56
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(998244353)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n), b(n);

  for(auto& x : a)cin>> x;
  for(auto& x : b)cin>> x;

  int dp[n][2] = {0}; // 0 -> not swap, 1 -> swap
  dp[0][0] = 1;
  dp[0][1] = 1;

  // Just simple no. of ways = number of subsets of swaps
  for(int i =1 ; i <n; i++){
    if(a[i-1] <= a[i] && b[i-1] <= b[i]){
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
    }
    if(a[i-1] <= b[i] && b[i-1] <= a[i]){
      dp[i][0] = (dp[i][0]+ dp[i-1][1])%MOD;
      dp[i][1] = (dp[i][1]+ dp[i-1][1])%MOD;
    }
  }
  cout << (dp[n-1][0] + dp[n-1][1])%MOD << endl;
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