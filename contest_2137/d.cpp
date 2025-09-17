/**
 *    author: Anicetus_7
 *    created: 2025-09-07 20:49:15
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#undef int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Value>
using umap = gp_hash_table<Key, Value>;
#define int long long


void Solve(){
  int n; cin >> n;

  vector<int> a(n);
  for(auto& x : a) cin >> x;

  umap<int,int> mp;
  umap<int,vector<int>> ind;
  for(int i = 0 ; i < n; i++){
    mp[a[i]]++;
    ind[a[i]].push_back(i);
  }

  int sum = 0;
  for(auto& [x, f] : mp){
    if(f%x != 0){
      cout << -1 << endl;
      return;
    }
    // sum += f;
  }
  
  // if(sum != n){
  //   cout << -1 << endl;
  //   return;
  // }

  int cnt = 1;
  vector<int> ans(n);
  for(auto& [x,f] :  mp){
    for(int i = 1; i <= f; i++){
      ans[ind[x][i-1]] = cnt;
      if(i%x == 0)cnt++;
    }
  }

  for(const auto& x : ans)
  {
    cout << x << " ";
  }
  cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin >> t;
  for(int i = 1; i <= t; i++){ 
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}