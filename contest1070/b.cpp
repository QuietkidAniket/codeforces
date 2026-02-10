/**
 *    author: Anicetus_7
 *    created: 2025-12-11 20:08:11
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
  string s; cin>>s;

  auto find = [&](int x, int y){
    int steps =0;
    while(x < y){
      x *=2;
      steps++;
    }
    return steps;
  };  
  int ans = 0;
  int i = 0;
  int res = 0;
  while(s[i] == '0'){
    i++;
    res = max(res, i);
  }
  int zero = 0;
  for(;i < n; i++){
    if(s[i] == '1'){
      ans = max(ans, zero);
      zero = 0;
    }else zero++;
  }


  if(res > 0){
    ans = max(ans, zero +res);
    // cout << "res : " << res<< endl;
  }else{ 
    ans = max(ans, zero);
  }
  cout << ans  << endl;
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