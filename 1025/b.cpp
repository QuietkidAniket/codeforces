/**
 *    author:  Anicetus_7
 *    created: 2025-06-18 18:40:10
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());





void Solve(){
  int m, n, a, b; cin>> m>>n>>a>>b;

  int ydist = max(a-1, m-a);
  int xdist = max(b-1, n-b);
  if(ydist > xdist){ // mouf makes horizontal partition 
    m = min(a-1, m-a);
    m++;
  }else{ // mouf makes vertical partition
    n = min(b-1, n-b);
    n++;
  }
  int x = 0, y =0;
  while((1<< x) < m)x++;
  while((1<< y) < n)y++;

  cout << x+y +1<< endl;
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