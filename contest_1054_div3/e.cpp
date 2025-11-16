/**
 *    author: Anicetus_7
 *    created: 2025-10-01 09:12:20
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
  int n,k,low,up; cin>>n>>k>>low>>up; 
  vector<int> a(n); for(auto& x : a)cin>> x;
  
  // find the subarrays containing atmost x elements and between low and up length
  auto find = [&](int x){ 
    if(x==0)return 0ll;
    int l= 0 , r= 0;
    int  res = 0;
    umap<int,int> mp;

    while(r< n){
      mp[a[r]]++;
      while(mp.size() > x && l <= r){
        mp[a[l]]--;
        if(mp[a[l]] == 0)mp.erase(a[l]);
        l++;
      }
      int len = r-l+1;
      if(len >= low){
        res += min(len,up) - low + 1;
      }
      r++;
    } 
    return res;
  };
  // if find(k) = subarrays with (<=k) distinct elements
  // subarrays with exactly k distinct elements = find(k) - find(k-1) 
  cout << find(k) - find(k-1) << endl;
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