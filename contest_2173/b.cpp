/**
 *    author: Anicetus_7
 *    created: 2025-12-05 20:14:31
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
  int a[n+1], b[n+1];
  for(int i =1;i <= n; i++) cin>>a[i];
  for(int i =1;i <= n; i++) cin>>b[i];

  int dp[n+1][2][2];
  dp[0][0][0] = dp[0][1][0] = 0;
  dp[0][0][1] = dp[0][1][1] = 0;
  for(int i =1;i <= n;i++){ 
    dp[i][0][0] = max(dp[i-1][0][0] - a[i], dp[i-1][1][0] - a[i]);
    dp[i][0][1] = min(dp[i-1][0][1] - a[i], dp[i-1][1][1] - a[i]);
    dp[i][1][0] = max(b[i] -dp[i-1][0][1], b[i] - dp[i-1][1][1] );
    dp[i][1][1] = min(b[i] -dp[i-1][0][0], b[i] - dp[i-1][1][0] );
  }
  cout << max(dp[n][0][0], dp[n][1][0]) << endl;

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