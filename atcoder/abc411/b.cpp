/**
 *    author: Anicetus_7
 *    created: 2025-06-23 11:35:05
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>> n; 
  vector<int> d(n);
  int prefix[n+1];
  prefix[0] = 0;
  for(int i = 0; i < n; i++){
    cin>> d[i];
    prefix[i+1]= prefix[i] + d[i];
  }
  for(int i = 0; i <n; i++){
    for(int j = i+1; j < n; j++){
      cout << prefix[j] -  prefix[i] << " ";
    }
    cout << endl;
  }
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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