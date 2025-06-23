/**
 *    author:  Anicetus_7
 *    created: 2025-06-20 02:38:00
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,k;
  cin>> n>>k;
  int ans = n;
  for(int i = 1; i*i <= n; i++){
    if(n %i == 0){
      if(n <= i*k){
        ans = min(ans, i);
      }
      if(i <= k){
        ans = min(ans, n/i);
      }
    }
  }
  cout << ans << endl;
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  int tt = clock();
  #endif
  
  int t = 1;
  cin>> t;
  while(t--){
  Solve();
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}