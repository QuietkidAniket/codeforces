/**
 *    author: Anicetus_7
 *    created: 2025-10-16 21:33:07
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(998244353)
#define MAX (int)(20005)
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
 
const int mod = MOD;
struct mint{
    int x;
 
    mint (){ x = 0;}
    mint (int32_t xx){ x = xx % mod; if (x < 0) x += mod;}
    mint (long long xx){ x = xx % mod; if (x < 0) x += mod;}
 
    int val(){
        return x;
    }
    mint &operator++(){
        x++;
        if (x == mod) x = 0;
        return *this;
    }
    mint &operator--(){
        if (x == 0) x = mod;
        x--;
        return *this;
    }
    mint operator++(int32_t){
        mint result = *this;
        ++*this;
        return result;
    }
    
    mint operator--(int32_t){
        mint result = *this;
        --*this;
        return result;
    }
    mint& operator+=(const mint &b){
        x += b.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint &b){
        x -= b.x;
        if (x < 0) x += mod;
        return *this;
    }
    mint& operator*=(const mint &b){
        long long z = x;
        z *= b.x;
        z %= mod;
        x = (int)z;
        return *this;
    }
    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }
    mint operator/=(const mint &b){
        return *this = *this * b.inv();
    }
    mint power(long long n) const {
        mint ok = *this, r = 1;
        while (n){
            if (n & 1){
                r *= ok;
            }
            ok *= ok;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        return power(mod - 2);
    }
    friend mint operator+(const mint& a, const mint& b){ return mint(a) += b;}
    friend mint operator-(const mint& a, const mint& b){ return mint(a) -= b;}
    friend mint operator*(const mint& a, const mint& b){ return mint(a) *= b;}
    friend mint operator/(const mint& a, const mint& b){ return mint(a) /= b;}
    friend bool operator==(const mint& a, const mint& b){ return a.x == b.x;}
    friend bool operator!=(const mint& a, const mint& b){ return a.x != b.x;}
    mint power(mint a, long long n){
        return a.power(n);
    }
    friend ostream &operator<<(ostream &os, const mint &m) {
        os << m.x;
        return os;
    }
    explicit operator bool() const {
        return x != 0;
    }
};
// Remember to check MOD

void Solve(){
  int n; cin>>n;
  int y = (int)log10(n) + 1;

  mint sum = (mint(10).power(n*y)-mint(1))/(mint(10).power(y)-mint(1));
  sum = sum * mint(n);
  cout <<sum <<endl; 
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