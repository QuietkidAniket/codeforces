/**
 *    author:  Anicetus_7
 *    created: 2025-06-17 13:18:45
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int  n; cin>> n;
  vector<int> x,y;
  for(int i =0; i < 2*n; i++){
    int u,v; cin>>u >> v;
    if(u == 0){
      y.push_back(abs(v));
    }else{
      x.push_back(abs(u));
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  double ans = 0;
  for(int i = 0; i< n ;i++){
    ans += sqrt(x[i]*x[i] + y[i]*y[i]);
  }
  cout << fixed<< setprecision(15) << ans << '\n';
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