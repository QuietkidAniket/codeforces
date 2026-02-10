/**
 *    author: Anicetus_7
 *    created: 2026-02-02 22:47:46
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  int k; cin>>k;
  vector<int> a(k);
  for(auto& x : a)cin>> x;
  int ans = 0;
  for(int s = 1;s < (1ll<<k); s++){
    int res = n;
    for(int bit =0; bit < k; bit++){
      if(s&(1ll<<bit)){
        res /= a[bit];
      }
    }
    if((int)__builtin_popcountll(s)&1){
      ans += res;
    }else ans -= res;
  }
  cout << ans << endl;
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