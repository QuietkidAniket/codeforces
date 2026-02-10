/**
 *    author: Anicetus_7
 *    created: 2025-12-06 14:31:43
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#undef int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Value>
using umap = gp_hash_table<Key, Value>;
#define int long long

void Solve(){
  string s,t;
  cin>>s>>t;

  umap<char,int> a;
  umap<char,int> b;

  for(char c : s)a[c]++;
  for(char c : t)b[c]++;

  for(auto [x, f]  : a){
    if(b[x] < f){
      cout << "Impossible\n";
      return;
    }
  }

  string res = "";
  for(auto [x,f] : b){
    while(b[x] > a[x]){
      b[x]--;
      res += x;
    }
  }
  sort(res.begin(), res.end());

  int ptr1 = 0, ptr2 = 0;
  while(ptr1 < s.size() || ptr2 < res.size()){
    if(ptr1 == s.size()){
      cout << res[ptr2];
      ptr2++;
    }else if(ptr2 == res.size()){
      cout << s[ptr1];
      ptr1++;
    }else if(s[ptr1] <= res[ptr2]){
      cout << s[ptr1];
      ptr1++;
    }else{
      cout << res[ptr2];
      ptr2++;
    }
  }
  cout <<endl;
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