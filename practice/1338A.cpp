/**
 *    author: Anicetus_7
 *    created: 2025-12-22 20:31:17
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  for(auto& x : a)cin>> x;
  vector<int> pmax(n);
  pmax[0] = a[0];
  for(int i =1;i< n; i++){
    pmax[i] = max(pmax[i-1] , a[i]);
  }
  int ans =0;
  for(int i = 0 ;  i < n; i++){
    int diff = pmax[i] -a[i];
    int msb_bit= 0;
    if(diff != 0)msb_bit = 64ll-__builtin_clzll(diff);
    ans = max(ans, msb_bit);
  }
  cout <<ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}