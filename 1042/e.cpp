/**
 *    author: Anicetus_7
 *    created: 2025-08-14 13:24:16
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define vec vector
void Solve(){
  int n; cin>> n;
  vec<int> a(n), b(n);

  for(auto& x : a)cin>> x;
  for(auto& x : b)cin>> x;

  if(a[n-1] != b[n-1]){
    cout << "NO\n";
    return;
  }
  for(int i = 0; i <n-1;i++){
    if(a[i] == b[i])continue;
    else if(b[i] == (a[i] ^ b[i+1]) || b[i] == (a[i] ^ a[i+1])){
      continue;
    }else{
      cout <<"NO\n";
      return ;
    }
  }
  cout << "YES\n";
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}