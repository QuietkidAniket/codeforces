/**
 *    author: Anicetus_7
 *    created: 2025-09-13 20:17:36
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,m; cin>>n>>m;
  int state = 0;
  int prev =0;
  int ans = 0;
  for(int i =0 ; i <n; i++){
    int a,b; cin>>a>>b;
    int t = a-prev;
    if(t&1){
      if(b== state){
        ans += t-1;
      }else ans+= t;
      state = b;
    }else{
      if(b== state){
        ans += t;
      }else ans += t-1;
      state = b;
    }
    prev = a;
  }
  ans += (m-prev);
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