/**
 *    author: Anicetus_7
 *    created: 2025-09-04 09:25:39
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int m,n; cin>> m >> n;
  vector<int> a(m), b(n);
  for(auto& x : a)cin>> x;
  for(auto& x : b)cin>> x;
  
  vector<vector<int>> dp(m+1, vector<int>(n+1,0));

  
  for(int i = 1; i<= m; i++)
  { 
    for(int j = 1; j<= n; j++)
    {
      if(a[i-1] == b[j-1]){
        dp[i][j] = 1+ dp[i-1][j-1];
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
      }
    }
  }
  int i = m, j = n;
  vector<int> ans;
  while(i >0 && j>0){
    if(a[i-1] == b[j-1]){
      ans.push_back(a[i-1]);
      i--; j--; 
    }else{
      if(dp[i-1][j] > dp[i][j-1]){
        i--;
      }else{
        j--;
      }
    }
  }
  cout << dp[m][n] << endl;
  reverse(ans.begin(), ans.end());
  for(const auto& x : ans)
  {
    cout << x<< " ";
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
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}
