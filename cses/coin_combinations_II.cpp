/**
 *    author: Anicetus_7
 *    created: 2025-09-04 12:48:41
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, target; cin>>n>> target;
  vector<int> a(n);
  for(auto& x : a)cin>> x;

  int dp[target+1]  = {0};
  
  // Distinct ordered ways
  dp[0] = 1ll;
  for(int coin : a)
  for(int t = target; t>=coin; t--)dp[t] = (dp[t]+dp[t-coin])%MOD;
  
  cout << dp[target] <<endl;
  
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