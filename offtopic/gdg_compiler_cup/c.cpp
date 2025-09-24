/**
 *    author: Anicetus_7
 *    created: 2025-09-22 22:12:32
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n,k; cin>>n>>k;
  vector<int> a(n);
  for(auto& x : a)cin>> x;
  int dp[n+1]=  {0};
  dp[0] = 0;

  for(int i = 1; i<= n; i++)
  { 
    int mx = 0;
    for(int j = 1; j<=min(k,i); j++)
    {
      mx = max(mx, a[i-j]);
      dp[i] = max(dp[i-j] + mx*j, dp[i]);
    }
  }
  cout << dp[n] << endl;
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