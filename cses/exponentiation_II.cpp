/**
 *    author: Anicetus_7
 *    created: 2025-09-21 12:26:02
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int modpow(int base,int exp, int MOD){
  if(base == 0 && exp  == 0)return 1ll;
  int res = 1ll;
  while(exp > 0){
    if(exp&1)res = (res * base)%MOD;
    base = (base* base)%MOD;
    exp >>=1;
  }
  return res;
}

const int mod = (int)(1e9  + 7);
void Solve(){
  int a,b,c; cin>>a>>b>>c;
  /**
   * a^b mod m = a ^ (b mod phi(m)) mod m
   * a^b^c mod m = a^ (b^c mod phi(m)) mod m
   * also, phi(m) = m-1 if m is prime
   * here, 1e9 + 7 is prime
   */
  cout << modpow(a, modpow(b,c,mod-1), mod) <<endl;
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