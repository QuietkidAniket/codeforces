/**
 *    author: Anicetus_7
 *    created: 2025-09-07 20:27:18
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int a,b; cin>>a>>b;
  if((a&1) && (b&1)){
    cout << a*b+1 << endl;
  }else if(a&1){
    if(b%4 != 0){
      cout << -1 << endl;
    }else{
      cout << a*(b/2) + 2 << endl;
    }
  }else if(b&1){
    cout << -1 << endl;
  }else{
    cout << max(a+b, a*(b/2) +  2) << endl;
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