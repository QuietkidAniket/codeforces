/**
 *    author: Anicetus_7
 *    created: 2025-07-02 20:35:28
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, k; cin>> n>>k;
  vector<int> a(n+1);
  for(int i = 1; i <=n-k+1; i++){
    a[i] = (n-k+1)-i+1;
  }
  for(int i = n-k+2; i <= n; i++){
    a[i] = i;
  }
  for(int i = 1; i <=n; i++)cout << a[i] << " ";
  cout<< endl; 
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