/**
 *    author: Anicetus_7
 *    created: 2025-07-01 20:37:40
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>> n;
  vector<int> a(n), prefix(n), suffix(n);
  for(int i = 0; i <n; i++){
    cin>> a[i];
  }
  prefix[0] = a[0], suffix[n-1] = a[n-1];
  for(int i = 1; i <n; i++){
    prefix[i] = min(prefix[i-1], a[i]);
  }
  for(int i = n-2; i >= 0; i--){
    suffix[i] = max(suffix[i+1], a[i]);
  }
  for(int i = 0; i< n; i++)
  {
    if( a[i] == prefix[i] || a[i] == suffix[i])cout << 1;
    else cout << 0;
  }
  cout << endl;
  
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