/**
 *    author: Anicetus_7
 *    created: 2025-09-06 21:16:45
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  string s1, s2; cin>>s1>>s2;


  int n = s1.size(), m= s2.size();

  int dp[n+1][m+1] = {0};  

  for(int i = 1; i <=n; i++)dp[i][0] = i;
  for(int i = 1; i <=m; i++)dp[0][i] = i;

  for(int i = 1; i<= n; i++)
  {
   for(int j = 1; j<= m; j++)
   {
    dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1] + (s1[i-1] != s2[j-1]) });
   } 
  }
  cout<< dp[n][m]<< endl;
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