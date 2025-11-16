/**
 *    author: Anicetus_7
 *    created: 2025-09-27 18:32:55
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
  int n,k; cin>>n>>k;
  string a; cin>>a;
  string b; cin>>b;

  unordered_set<char> r;
  umap<char, vector<int>> changes;
  for(int i = 0; i < n; i++){
    if(a[i] == b[i])continue;
    r.insert(a[i]); 
    changes[a[i]].push_back(i);
  } 

  vector<int> cand(r.begin(), r.end());
  int z = cand.size();

  auto find = [&](int subset){
    // replace all the elements with correct elements
    string t(a.begin(), a.end());
    for(int i = 0; i <= 10; i++){
      if(subset & (1ll<<i)){
        for(int idx : changes[cand[i]]){
          t[idx] = b[idx];
        }
      }
    }
    // compute max [l,r]'s
    int l= 0, r= 0;
    int sum = 0;
    while(r < n){
      if(t[r] == b[r]){ 
        if(l == -1){
          l = r;
          sum++;
        }else{
          sum += r-l+1;
        }
      }else l = -1;
      r++;
    }
    return sum;
  };

  if(z <= k){
    cout << n*(n+1)/2;
  }else{
    int ans = 0;
    // subset of characters to be changed
    for(int s = 0; s < (1ll<<z); s++){
      if(__builtin_popcount(s) > k)continue;
      int res = find(s);
      ans =max(ans, res);
    }
    cout <<ans;
  }
  cout << endl;
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