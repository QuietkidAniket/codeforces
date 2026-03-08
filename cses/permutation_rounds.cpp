/**
 *    author: Anicetus_7
 *    Submission from Mobile Phone
**/
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
 
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <utility>
#include <tuple>
#include <iterator>
 
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <random>
#include <chrono>
#include <limits>
#include <climits>
 
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(1e12+1)
 
 // Combinations
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
 
int lcm(int a, int b){
	return a*b/gcd(a,b);
}
 
void Solve() {
   int n;  cin>>n;
   vector<int> p(n+1), vis(n+1, 0);
   for(int i=1; i<=n; i++)cin>>p[i];
   vector<int> spf(n+1);
   iota(spf.begin(), spf.end(), 0);
   // spf-> smallest prime factor
   for(int i = 2; i <=n ;i++){
       if(spf[i] == i)for(int j = i*i; j<=n;j+=i){
           if(spf[j] == j)spf[j] = i;
       }
   }
   function<int(int)> dfs = [&](int i)-> int{
   	vis[i]= 1;
   	int ai= p[i];
   	if(vis[ai])return 1;
   	else return 1+ dfs(ai);
   };
   
   map<int,int> exp;
   for(int i = 1; i <= n; i++){
       int len = 0;
       if(!vis[i])  len = dfs(i);
       
       int temp  =len;
       while(temp > 1){
           int prime = spf[temp];
           int cnt  = 0;
           while(temp%prime == 0){temp /= prime;cnt++;}
           exp[prime] = max(exp[prime], cnt);
       }
   }
   int ans =1;
   for(auto& [p, alpha] :  exp){
       ans *= modPow(p, alpha);
       ans %= MOD;
   }
   cout<< ans<<endl;
}
 
//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    // cin>> t;
    // precompute_combinations();
    for(int i = 1; i <= t; i++) {
        Solve();
    }
    return 0;
}