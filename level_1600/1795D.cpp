/**
 *    author: Anicetus_7
 *    created: 2025-08-07 23:31:06
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(998244353)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 5;
int fact[MAXN+1], invfact[MAXN+1];
int modPow(int base, int exp) {
  int res = 1;
  while (exp > 0) {
      if (exp & 1ll) res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1ll;
  }
  return res;
}

int modinv(int a) {
    return modPow(a, MOD - 2);
}
void precompute_combinations(){
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
      }
    
    invfact[MAXN] = modinv(fact[MAXN]);
    for(int i = MAXN-1; i >= 0;i--){
      invfact[i] = invfact[i+1]*(i+1) % MOD;
    }
}
int C(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}


void Solve(){
  int n; cin>>n;
  int a[n];
  // for(auto& x : a)cin>>x;
  for(int i = 0; i< n; i++)
  {
   cin>>a[i] ;
  }

  int ans = C(n/3, n/6);

  for(int i =0 ; i <n; i+=3){
    sort(a+i, a+i+3);
    if(a[i] == a[i+2]){
      ans = (3*ans)%MOD;
    }else if(a[i] == a[i+1]){
      ans = (2*ans)%MOD;
    }
  }
  cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  precompute_combinations();
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}