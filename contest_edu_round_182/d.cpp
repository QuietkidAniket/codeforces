/**
 *    author: Anicetus_7
 *    created: 2025-09-15 21:16:29
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
  int n, y; cin>>n>>y;
  unordered_set<int> st;
  unordered_map<int,int> mp; 
  vector<int> a(n); for(auto& x : a){cin>> x;st.insert(x);mp[x]++;}

  vector<int> b;
  for(const auto& x : st){
    // factors;
    for(int k=2; k <= x; k++){
      int t = ceil(x/(double)k);
      if(st.find(k) != st.end()){
        b.push_back(t);
      }
      if(st.find(t) != st.end()){
        b.push_back(k);
      }
    }
  }

  int mx = -INF;
  for(const auto& x : b){
    umap<int,int> n_mp;
    int sum = -y*n;
    for(int i = 0; i< n; i++)
    {
      int t = ceil(a[i]/(double)(x));
      n_mp[t]++;
      sum += t;
    }
    for(auto& [x,f]: n_mp){
      sum += y*min(mp[x], f);
    }
    mx = max(sum, mx);
  }
  cout << mx << endl;

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