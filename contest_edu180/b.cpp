/**
 *    author: Anicetus_7
 *    created: 2025-06-23 20:35:27
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  for(auto& x:a){
    cin>>x;
  }
  int ans = 1e7;
  for(int i = 0; i < n-1; i++){
    int x = a[i];
    int sign = (x < a[i+1]);
    for(int j = i+1; j< n; j++)
    {
      int y = a[j];
      if(abs(x-y) <= 1){
        ans = min(ans, j-i-1);
        break;
      }

      if(sign ==1){
        if(a[j-1] < y )continue;
        else{
          ans = min(ans, j-i-1);
          break;
        }
      }else{
        if(a[j-1] > y )continue;
        else{
          ans = min(ans, j-i-1);
          break;
        }
      }
    }
  }
  if(ans >= n-1 || ans == 1e7)cout << -1 << endl;
  else cout << ans << endl;
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