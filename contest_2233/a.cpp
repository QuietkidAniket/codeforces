/**
 *    author: Anicetus_7
 *    created: 2026-06-09 20:09:53
**/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#else
#define DEBUG(x) 42 
#endif
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,x,y,z; cin>>n>>x>>y>>z;
  int mn = INF;
  for(int i =1;i<= 10000; i++){
    if(x*i + max(0ll,y*10*(i-z)) >= n){
      mn = i;
      break;
    }
  }
  for(int i =1;i<= 10000; i++){
    if(x*i + y*i >= n){
      mn = min(mn, i);
      break;
    }
  }
  cout << mn << endl;
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