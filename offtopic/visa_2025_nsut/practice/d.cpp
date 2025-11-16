/**
 *    author: Anicetus_7
 *    created: 2025-09-30 19:13:24
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
  vector<int> a(n); for(auto& x : a)cin>> x;

  // sorts the skyscrapers based on height, and tracks their indices
  map<int, vector<int>> mp;

  for(int i =0 ;i <n;i++){
    mp[a[i]].push_back(i); 
  }
  if(mp.size() == 1 && mp.begin()->first == 0){
    cout << 0 <<endl;
    return;
  }

  set<int> st;
  st.insert(-1);
  st.insert(n);

  int t = min(n, mp.begin()->first);
  int ans = t*t;
  for(auto& [x, vec] : mp){
    for(int idx : vec){
      auto ub = st.upper_bound(idx);
      int l = 0, r=  n-1; 
      r = min(r, *ub);
      ub--;
      l = max(l, *ub);
      int t = min(x, r-l-1);
      ans = max(t*t,ans);
    }
    for(int idx : vec){
      st.insert(idx);
    }
  }
  cout << ans  <<endl;
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
