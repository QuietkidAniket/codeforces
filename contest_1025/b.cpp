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

  vector<pair<int,int>> arr = {
    {a, n},  
    {m-a+1,  n},
    {m, b},
    {m ,n-b+1}
  };


  int ans = n+m;

  for(int i= 0; i < 4; i++){

    int x = 0, y =0;

    while(arr[i].first > 1){
      x++;
      arr[i].first = (arr[i].first+1)/2;
    }
    while(arr[i].second > 1){
      y++;
      arr[i].second = (arr[i].second+1)/2;
    }

     ans = min(ans,x+y);
  }
  cout << ans + 1 <<'\n';
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