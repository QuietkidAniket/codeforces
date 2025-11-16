/**
 *    author: Anicetus_7
 *    created: 2025-10-09 07:47:11
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<string> a(n);
  vector<string> b(n);

  for(auto& x : a)cin>> x;
  for(auto& x : b)cin>> x;

  string res = "";
  unordered_map<string,bool> mp;

  vector<bool> ans(n, false);

  for(int i = 0 ; i < n ; i++){
    res = res + a[i];
    if(b[i] == res || mp.find(a[i]) != mp.end()){
      ans[i] = true;
    }
    mp[res] = true;
  }

  for(auto x : ans){
    cout << x  <<" ";
  }
  cout << endl;
  
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