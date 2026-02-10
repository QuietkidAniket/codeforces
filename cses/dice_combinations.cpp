/**
 *    author: Anicetus_7
 *    created: 2025-09-04 12:34:59
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,a,b; cin>>n>>a>>b;
  vector<int> dp(6*n+1, 0);
  
  dp[0] = 1ll;
  for(int t = 1; t<=6*n; t++)
  for(int outcome = 6; outcome>= 1; outcome--)if(outcome <= t)dp[t] = (dp[t]+dp[t-outcome]);
  double sum  = 0;
  for(int i = a; i<= b; i++)sum += dp[i];
  cout << (sum/(double)pow(6,n)) <<endl;
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
 
