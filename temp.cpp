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