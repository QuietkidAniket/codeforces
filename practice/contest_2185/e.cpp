/**
 *    author: Anicetus_7
 *    created: 2026-01-18 22:38:28
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
  int l; cin>>l;
  int k; cin>>k;
  vector<int> a(n+1,0);
  vector<int> b(n+1,0);
  for(int i= 1; i <= n ;i++)cin>>a[i];
  for(int i= 1; i <= n ;i++)cin>>b[i];
  a.push_back(l);
  b.push_back(0);
  vector<vector<vector<int>>> dp(n+2, vector<vector<int>>(k+1, vector<int>(2,0)));
  for(int i =1; i <= n+1; i++){ 
    for(int j =0; j <= k; j++){
      // not take
      dp[i][j][0] = dp[i-1][j][1]*(a[i]-a[i-1]) +  dp[i-1][j][0];
      dp[i][j][1] = dp[i-1][j][1];
      // take 
      if(j > 0 && dp[i][j][0] <=  b[i]*(a[i]-a[i-1]) +  dp[i-1][j-1][0]){
        dp[i][j][0] = b[i]*(a[i]-a[i-1]) +  dp[i-1][j-1][0];
        dp[i][j][1] = b[i];
      }
    }
  }
  cout <<dp[n+1][k][0] << endl;
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