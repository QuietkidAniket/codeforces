/**
 *    author: Anicetus_7
 *    created: 2025-10-23 10:39:06
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
  int n; cin>>n;
  string s; cin>>s;
  int a[n];
  for(int i =0 ;i < n;i++){
    a[i] = (s[i] -'0');
  } 
  int sum = 0;
  umap<int,int> freq;
  int cnt =0;
  freq[0]++;
  for(int i =0 ;i <n ;i++){
    sum += a[i];
    cnt += freq[sum - (i+1)];
    freq[sum - (i+1)]++;
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