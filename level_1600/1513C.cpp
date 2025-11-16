/**
 *    author: Anicetus_7
 *    created: 2025-11-06 16:23:07
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// stores the length of the final number after i operations have been performed on the number '10'
int dp[MAX];

void Solve(){
  int n,m ; cin>>n>>m;
  

  int ans =0;
  while(n > 0){
    int d = n%10;
    int steps  = m - (10-d);
    if(steps >= 0)ans += dp[steps];
    else ans++;
    ans %= MOD;
    n /= 10;
  }

  cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;

  // precompute dp
  for(int i =0; i <9; i++)dp[i] = 2;
  dp[9] = 3;
  for(int  steps =10; steps < MAX; steps++){
    dp[steps] = dp[steps-9] +  dp[steps-10];
    dp[steps] %= MOD;
  }

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