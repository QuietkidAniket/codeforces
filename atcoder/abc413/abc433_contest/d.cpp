/**
 *    author: Anicetus_7
 *    created: 2025-11-28 21:46:45
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int modPow(int base, int exp, int m) {
  int res = 1;
  while (exp > 0) {
      if (exp & 1ll) res = (res * base) % m;
      base = (base * base) % m;
      exp >>= 1ll;
  }
  return res;
}

void Solve(){
  int n,m; cin>> n >>m;
  int a[n];
  for(auto& x: a) cin>>x;

  vector<unordered_map<int,int>> mp(11);
  for(int i =0 ;i < n; i++){
    mp[to_string(a[i]).size()][a[i]%m]++;
  }
  int cnt =0;
  for(int ai : a){
    for(int k = 1; k <= 10; k++){
      int res  = (modPow(10ll, k, m) *ai*-1) %m;
      res += m;
      res %= m;
      cnt += mp[k][res];
    }
  }
  // ai *= 10, ai %= m;
  // const int key = (m - ai) % m;
  cout<< cnt<<endl;
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