/**
 *    author: Anicetus_7
 *    created: 2026-01-12 20:30:37
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int s, k,m; cin>>s>>k>>m;
  int res=  m / k;
  int t = m%k;
  if(s >= k){
    if(res&1){ // k -> 0
      cout << max(0ll, k - t) << endl;  
    }else{ //s -> s-k
      cout << max(0ll,s - t) << endl;
    } 
  }else{
    cout << max(0ll, s - m%k) << endl;
  }
  
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