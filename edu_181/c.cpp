/**
 *    author: Anicetus_7
 *    created: 2025-07-22 21:20:39
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int l,r; cin>>l>>r;
  int ans = 0;
  vector<int> a = {2,3,5,7};

  for(int i = 0; i < (1 << 4); i++){
    int num  = 1;
    for(int j = 0; j < 4; j++){
      if((i >> j) & 1){
        num *= a[j];
      }
    } 
    int w = r/num - (l-1)/num;
    if(__builtin_popcount(i) & 1)ans -= w;
    else ans += w;
  }
  cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}
