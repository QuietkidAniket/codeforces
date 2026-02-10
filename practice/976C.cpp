/**
 *    author: Anicetus_7
 *    created: 2025-12-22 13:56:58
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
  vector<pair<pair<int,int>,int>> a(n);
  for(int i = 0 ; i < n; i++){
    cin>>a[i].first.first>> a[i].first.second;
    a[i].second = i+1;
  }

  // sort based on ending coordinates
  sort(a.begin(), a.end(), [](const pair<pair<int,int>,int>& x, const pair<pair<int,int>,int>& y){
    if(x.first.second == y.first.second)return x.first.first > y.first.first;
    else return x.first.second < y.first.second;
  });


  // find whether for current ith element 
  // there exists any segment jth having l[j] >= l[i] , j < i 
  // j < i implies that  r[j] <= r[i] ... 
  // so if l[j] >= l[i], then segment j lies  within i
  oset<pair<int,int>> st;
  for(auto& [p, idx] : a){
    auto [l,r] = p;
    int ord= st.order_of_key({l-1, INF});
    if(ord < st.size()){
      auto key = st.find_by_order(ord);
      cout << key->second <<" " <<idx << endl;
      return;
    }
    st.insert({l, idx});
  }
  cout << "-1 -1\n";
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