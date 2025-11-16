/**
 *    author: Anicetus_7
 *    created: 2025-11-01 13:41:31
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n, k,p;  cin>>n>>k>>p;

  int a[n+1][k];
  for(int i = 1; i<= n; i++)for(int j =0 ; j < k; j++)cin>>a[i][j];
  int dp[n+1][p+1];
  memset(dp, 0, sizeof dp);
  for(int i =1;i <=n; i++){
    memcpy(dp[i], dp[i-1], sizeof(dp[i]));
    int sum  =0;
    for(int j =0 ; j < k; j++){
      sum += a[i][j];
      for(int capacity = j+1; capacity<= p; capacity++){
        dp[i][capacity] =  max(dp[i-1][capacity-j-1] + sum, dp[i][capacity]);
      }
    }
  }
  cout << dp[n][p] << endl;
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