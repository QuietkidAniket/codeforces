/**
 *    author: Anicetus_7
 *    created: 2025-08-06 20:04:14
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int a,b, c,d; cin>>a>>b>>c>>d;  
    int x = 5*a + b;
    int y = 5*c + d;
    if (x <y) {
        cout << "NO\n";
        return;
    }else{
      int diff = x-y;
      if (diff % 6 != 0ll){
          cout << "NO\n";
          return;
      }
      cout << "YES\n";
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}