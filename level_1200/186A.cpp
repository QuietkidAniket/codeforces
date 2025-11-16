/**
 *    author: Anicetus_7
 *    created: 2025-11-14 11:38:13
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  string s; cin>>s;
  string t; cin>>t;
  if(s.size() != t.size()){
    cout << "NO\n";
    return;
  }

  if(s == t){
    cout << "YES\n";
    return;
  }
  int idx  = -1;
  bool flag = false;
  for(int  i =0 ;i < s.size(); i++){
    if(s[i] != t[i]){
      if(idx == -1)idx =i;
      else{
        swap(s[idx], s[i]);
        break;
      }
    }
  }
  if(s == t)cout << "YES" << endl;
  else cout << "NO" << endl;
  
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