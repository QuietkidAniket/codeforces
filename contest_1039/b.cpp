/**
 *    author: Anicetus_7
 *    created: 2025-07-27 20:37:48
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> p(n); for(auto& x : p)cin>>x;

  int l = 0, r = n-1;
  string res;
  int flag = 1; // next sign ... < : 1, > : 0
  while(l < r){
    if(flag){
      if(p[l] < p[r]){
        res.push_back('L');
        res.push_back('R');
      }else{
        res.push_back('R');
        res.push_back('L');
      }
    }else{
      if(p[l] < p[r]){
        res.push_back('R');
        res.push_back('L');
      }else{
        res.push_back('L');
        res.push_back('R');
      }
    }
    l++, r--;
    flag = 1 - flag;
  }
  if(l == r)res.push_back('L');
  cout << res << endl;

  
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