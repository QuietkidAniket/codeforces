#define MOD (int)(1e9+7)
const int MAXN = 2e6 + 5;
int fact[MAXN], invfact[MAXN];
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
void precompute_combinations() {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = modinv(fact[i]);
    }
}
int C(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}