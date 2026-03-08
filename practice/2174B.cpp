/**
 *    author: Anicetus_7
 *    created: 2026-01-18 18:58:39
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
  int k; cin>>k;

  vector<int> a(n+1); 
  for(int i = 1; i<= n; i++)
  {
   cin>>a[i]; 
  }

  vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2,0)));
  for(int i = 1; i <= n ; i++){
    for(int coins = 0; coins <=k; coins++){
      dp[i][coins][0] = dp[i-1][coins][0] + dp[i-1][coins][1];
      for(int c= 0; c <= coins; c++){
        // not take
        if(c <= a[i]){
          // take
          // if(dp[i-1][coins-c][0] +  c > dp[i-1][coins][0] +  dp[i-1][coins][1] && c > dp[i-1][coins][1]){
            dp[i][coins][0] = max(dp[i-1][coins][0]+ c, dp[i][coins][0]);
            dp[i][coins][1] = max(dp[i-1][coins][1], c);
          // }
        }
      }
    }
  }
  int ans =0;
  for(int coins = 0 ; coins <= k; coins++){
    ans= max(ans, dp[n][coins][0]);
  }
  cout << ans << endl;
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