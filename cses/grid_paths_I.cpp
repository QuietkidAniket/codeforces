/**
 *    author: Anicetus_7
 *    created: 2025-09-04 19:52:16
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int n;
inline bool check(int x, int y){
  return x >= 0 and y >=0 and x< n && y < n;
}
void Solve(){
  cin>>n;

  vector<vector<char>> grid(n, vector<char>(n));

  for(int i = 0; i< n; i++)
  {
   for(int j = 0; j< n; j++)
   {
    cin>>grid[i][j];
   } 
  }

  vector<vector<int>> dp(n, vector<int>(n,0));
  dp[0][0] = (grid[0][0] == '.');

  for(int i= 0; i < n; i++){
    for(int j= 0; j <n; j++){
      if(grid[i][j] == '*')continue;

      if(check(i-1, j) && grid[i-1][j] == '.'){
        dp[i][j] = (dp[i][j]  + dp[i-1][j])%MOD;
      }
      if(check(i, j-1) && grid[i][j-1] == '.'){
        dp[i][j] = (dp[i][j]  + dp[i][j-1])%MOD;
      }
    }
  }

  cout << dp[n-1][n-1]%MOD;

  
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