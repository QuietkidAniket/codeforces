/**
 *    author:  Anicetus_7
 *    created: 2025-06-18 20:13:03
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>> n;
  int cnt =1;
  int jury;
  cout << "digit" << '\n';
  cout.flush();
  cin>> jury;
  cout << "digit" << '\n';
  cout.flush();
  cin>> jury;
  cout << "add -8" << '\n';
  cout.flush();
  cin>>jury;
  cout << "add -4" << '\n';
  cout.flush();
  cin>>jury;
  cout << "add -2" << '\n';
  cout.flush();
  cin>>jury;
  cout << "add -1" << '\n';
  cout.flush();
  cin>> jury;
  cout << "add "<<  n-1 << '\n';
  cout.flush();
  cin>> jury;
  cout << "!" << '\n';
  cout.flush();
  cin>> jury;
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