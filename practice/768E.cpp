/**
 *    author: Anicetus_7
 *    created: 2025-12-29 15:39:25
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
  static map<pair<int,int>,int> cache;
  function<int(int,int)> nimber = [&](int stones, int mask)-> int {
    if(stones == 0)return 0;
    if(stones<  0)return -1;
    if(cache.count({stones, mask}))return cache[{stones, mask}];
    unordered_set<int> st;
    for(int i = 1;i <= stones; i++){
      if(mask&(1<<i))continue;
      st.insert(nimber(stones - i, mask^(1ll<<i)));
    }
    int mex  = 0;
    while(st.count(mex))mex++;
    return cache[{stones, mask}] = mex;
  };

  int xor_sum = 0ll;
  for(int i = 0; i < n ;i++){
    int heap; cin>>heap;
    xor_sum ^= nimber(hi,0ll);
  }
  if(!xor_sum)cout << "YES\n";
  else cout << "NO\n";
  
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