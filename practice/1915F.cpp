/**
 *    author: Anicetus_7
 *    created: 2025-12-19 19:15:11
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
  int n; cin>>n;
  vector<pair<int,int>> a(n);
  for(auto& [l,r] : a)cin>>l>>r;  

  sort(a.begin(), a.end(), [&](const pair<int,int>& x, const pair<int,int>& y){
      if(x.second == y.second)return x.first < y.first;
      return x.second < y.second;
  });

  oset<int> st;
  int cnt = 0;
  for(int i = 0; i<n; i++){
    int res = st.size() - st.order_of_key(a[i].first);
    cnt += res;
    st.insert(a[i].first);
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