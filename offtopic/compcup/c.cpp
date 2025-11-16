/**
 *    author: Anicetus_7
 *    created: 2025-10-02 21:08:58
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
  int n,m; cin>>n>>m;

  vector<int> a(n);
  for(auto& x : a)cin>> x;

  // int prefix[n+1]= {0};
  // prefix[0] = 0;

  // int tot = 0;
  // for (int i = 0; i < n; i++) {
  //   tot = (tot+a[i])%m;
  //   prefix[i+1] = (prefix[i] + a[i]) % m;
  // }
  // umap<int,int> mp;
  // mp[0] =1;
  // just normal sum == k subarray counting
  // int cnt = 0;
  for(int i = 0; i < n; i++) {
    int sum = 0;
    for(int len = 1; len < n; len++) { 
      sum = (sum + a[(i+len-1)%n]) % m;
      if(sum % m == 0) cnt++;
    }
  } 
  cout << cnt <<endl;
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