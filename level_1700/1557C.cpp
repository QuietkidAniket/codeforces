/**
 *    author: Anicetus_7
 *    created: 2025-11-16 13:16:19
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int modPow(int base, int exp) {
  int res = 1;
  while (exp > 0) {
      if (exp & 1ll) res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1ll;
  }
  return res;
}

void Solve(){
  int n; cin>>n;
  int k; cin>>k;

  int dp[k+1][2]; // [i][0] -> equals, [i][1] -> AND > XOR, [i][2] = AND < XOR

  dp[k][0] = 1;
  dp[k][1] = 0;

  int n_total = modPow(2,n);
  int n_even = modPow(2,n-1);
  if(n&1){
    n_even++;
  }else n_even--;

  for(int i = k-1; i >= 0; i--){
    dp[i][0] =  dp[i+1][0] * n_even;
    dp[i][1] =  dp[i+1][1] * n_total +  dp[i+1][0]*(n%2==0);
    dp[i][0] %= MOD;
    dp[i][1] %= MOD;
  }
  cout << (dp[0][0] +  dp[0][1] )%MOD<< endl;
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