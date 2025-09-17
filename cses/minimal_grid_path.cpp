/**
 *    author: Anicetus_7
 *    created: 2025-09-06 22:21:34
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n; cin >> n;
      
    vector<string> grid(n);
    for(int i = 0; i< n; i++)
    {
     cin>>grid[i]; 
    }

    // dp[i][j] = minimal steps to reach (i,j)
    vector<vector<int>> dp(n+1, vector<int>(n+1,0ll));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
          dp[i][j] = (int)(grid[i-1][j-1]-'A'+1ll) + max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i =n, j = n;
    while(i > 0 && j > 0){
      if(dp[i][j] > )
    }

    cout << dp[n][n] << "\n";
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