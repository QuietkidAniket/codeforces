/**
 *    author: Anicetus_7
 *    created: 2025-10-18 23:50:27
**/
#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e18
#define ll long long
#define MOD (int)(1e9 + 7)
#define MAX (int)(1e14)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const ll MAXN = 1e14;
static int fact[MAXN+1], invfact[MAXN+1];
int modPow(ll base, ll exp) {
  ll res = 1;
  while (exp > 0) {
      if (exp & 1ll) res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1ll;
  }
  return res;
}

int modinv(ll a) {
    return modPow(a, MOD - 2);
}
static bool flag = false;
void precompute_combinations(){
    fact[0] = invfact[0] = 1;
    for(ll i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
      }
    
    invfact[MAXN] = modinv(fact[MAXN]);
    for(ll i = MAXN-1; i >= 0;i--){
      invfact[i] = invfact[i+1]*(i+1) % MOD;
    }
}
int C(ll n, ll r) {
    if(!flag){precompute_combinations();flag = true;}
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}


void Solve(){
  int n,a,b; cin>>n>>a>>b; 
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main_(){
    auto begin = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t = 1;
    cin >> t;
    
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        Solve();
    }
    
    auto end = chrono::high_resolution_clock::now(); 
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin); 
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}
void* run_main(void*) {
    main_(); 
    return nullptr;
}

int32_t main() {
    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    size_t stack_size = 1024UL * 1024UL * 1024UL; // 1 GB
    pthread_attr_setstacksize(&attr, stack_size);

    if (pthread_create(&thread, &attr, run_main, nullptr) != 0) {
        perror("pthread_create");
        return 1;
    }

    pthread_join(thread, nullptr);
    pthread_attr_destroy(&attr);

    return 0;
}