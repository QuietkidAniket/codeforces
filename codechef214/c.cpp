/**
 *    author: Anicetus_7
 *    created: 2025-11-26 20:31:08
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>> n;
  int a[n]; for(auto& x : a) cin>>x;
  int b[n]; for(auto& x : b) cin>>x;
  bool  flag= false;
  for(int i = 0;i < n-1; i++){  
      if(a[i] > a[i+1]){
        if(b[i] <= b[i+1]){
          flag = true;
          break;
        }
      }else if(b[i] >= b[i+1]){
        flag = true;
        break;
      }
  }
  if(flag)cout <<"NO\n";
  else cout << "YES\n"; 
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