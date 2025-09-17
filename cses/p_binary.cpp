/**
 *    author: Anicetus_7
 *    created: 2025-09-05 20:36:27
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int num1, num2; cin>>num1>>num2;
  for(int i = 1; i <= 60; i++){
      int res = num1 - i * num2;
      if(res <= 0)break;
      int cnt = __builtin_popcountll(res);
      if(cnt <= i){
          if(i >1 && cnt==1 && (64 -__builtin_clzll(res)-1) < i){
              continue;
          }
          cout << i << endl;
          return;
      } 
  }
  cout << -1<< endl;
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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