/**
 *    author: Anicetus_7
 *    created: 2025-12-27 20:09:41
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
  char cur  = 'u';
  int cnt =0;
  for(int i =0 ; i <s.size(); i++){
    if(s[i] == 'u'){
      if(cur=='u'){
        cur = 's';
        s[i] = 's';
        cnt++;
      }else cur ='u';
    }else if(s[i] == 's')cur = 's';
  }
  if(s.back() == 'u')cnt++;
  cout << cnt << endl;
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