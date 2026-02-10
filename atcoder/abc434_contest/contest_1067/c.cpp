/**
 *    author: Anicetus_7
 *    created: 2025-11-29 20:47:31
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int dp[MAX][2]; // local maximum at i if : [0] -> a[i] is taken, [1] -> a[i] + b[i] is taken

void Solve(){
  int n,k; cin>>n>>k;
  int a[n],b[n];
  for(auto& x: a)cin>>x;
  for(auto& x: b)cin>>x;

  int res[2];
  res[0] = res[1] = -INF;

  for(int i = 1; i<= n; i++)
  {
    // not take
    dp[i][0] = a[i-1] + max(dp[i-1][0], 0ll);
    res[0] = max(res[0], dp[i][0]);

    // take
    dp[i][1] = a[i-1] + max(dp[i-1][1], 0ll);
    dp[i][1] = max(dp[i][1], a[i-1]+ b[i-1] + max(0ll, dp[i-1][0]));
    res[1] = max(res[1], dp[i][1]);
  }
  cout << res[k%2] << endl;
  
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