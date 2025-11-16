/**
 *    author: Anicetus_7
 *    created: 2025-11-03 17:48:51
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(998244353)
#define MAX (int)(1e6+1)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n; cin>>n;
  int dp[n+1];
  memset(dp, 0, sizeof dp);
  dp[0] = 1;
  for(int i =1; i <= n; i++){
    for(int j = i; j <= n; j+=i)dp[j]++;
  }
  int sum = 0;
  for(int i =2;i <= n; i++){
    sum = sum + dp[i-1]; sum %= MOD;
    dp[i] = (dp[i]+sum)%MOD;
  }
  cout << dp[n] << endl;
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