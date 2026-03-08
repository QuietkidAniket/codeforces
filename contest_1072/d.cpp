/**
 *    author: Anicetus_7
 *    created: 2026-01-12 21:44:54
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 5;
static int fact[MAXN+1], invfact[MAXN+1];
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
static bool flag = false;
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
    if(!flag){precompute_combinations();flag = true;}
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}
// _________________ dont forget to run precompute_combinations() !______________

void Solve(){
  int n; cin>>n;
  int k; cin>>k;
  
  if(k >= 62){
    cout << 0 << "\n";
    return;
  }

  int d = __builtin_ctzll(n); 
  int res = 0;

  if(d + 1 <= k)res++;  
  // cout << d <<endl;
  for (int i = 1; i <= d; i++){
    int avail = k-i; 
    if(avail < 0)break;
    if(avail >= i-1){
      res += (1ll << (i-1));
    }else{
      for(int j = 0; j<= avail; j++){
        res += C(i-1, j);
      }
    }
  }
  cout << n - res << "\n";
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
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}