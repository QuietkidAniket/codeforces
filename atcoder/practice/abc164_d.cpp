/**
 *    author: Anicetus_7
 *    created: 2025-12-11 07:33:45
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int) (2019) 
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  string s; cin>>s;
  int cnt =0;
  int prev =0;
  int alpha = 1;  
  reverse(s.begin(), s.end());
  map<int,int> mp;
  mp[0] = 1;
  for(char c : s){
    int cur = ((c-'0')*alpha)%MOD + prev;
    cur %= MOD;
    cnt += mp[cur];
    alpha *=10;
    alpha %= MOD;
    mp[cur]++;
    prev = cur;
  }
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