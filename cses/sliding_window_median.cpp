/**
 *    author: Anicetus_7
 *    created: 2026-01-17 19:42:18
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// #undef int
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// #undef int
// template<typename T>
// using mset = tree<
//    pair<T, int>, // use index or timestamp to break ties
//    null_type,
//    less<pair<T, int>>,
//    rb_tree_tag,
//    tree_order_statistics_node_update>;
// #define int long long

#undef int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using oset = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;
#define int long long


void Solve(){
  int n, k; cin>>n>>k;
  vector<int> a(n);
  for(auto& x : a)cin>> x;
  oset<pair<int,int>> st;
  for(int i =0;i <k; i++){
    st.insert({a[i], i});
  }
  cout << st.find_by_order((k-1)/2)->first << " ";
  for(int i =k;i <n; i++){
    st.insert({a[i], i});
    st.erase(st.find({a[i-k], i-k}));
    cout << st.find_by_order((k-1)/2)->first << " ";
  }
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