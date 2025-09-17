/**
 *    author: Anicetus_7
 *    created: 2025-09-13 19:06:45
**/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

/** @brief Multiset solution */

void Solve(){
  int n,q; cin>>n>> q;
  vector<int> a(n), b(q);
  for(auto& x : a)cin>> x;
  for(auto& x : b)cin>> x;
  multiset<pair<int,int>> st;
  for(int i = 0; i< n; i++){
    st.insert({a[i], i+1});
  }
  for(auto x : b){
    auto p = st.lower_bound({x,0});
    if(p == st.end() || p->first < x){
      cout << 0 << " ";
      continue;
    }else{
      cout << p->second << " ";
      if(p->first-x > 0){
        st.insert({p->first-x, p->second});
      }
      st.erase(p);
    }
  }
}
 
/** @brief Segment Tree Alternative solution */

// struct  segtree{
//   vector<int> tree;
//   int size;
//   void init(int n){
//     tree.resize(4*n);
//     size = n;
//   }
//   void build(vector<int>& a, int idx, int l, int r){
//     if(l == r){
//       tree[idx] = a[l];
//       return;
//     }
//     int mid = (l+r)>>1;
//     // build left subtree
//     build(a, 2*idx, l, mid);
//     // build right subtree
//     build(a, 2*idx +1, mid +1, r);
//     // take max of the left and right subtree
//     tree[idx] = max(tree[2*idx], tree[2*idx +1]);
//   }
//   // query for the a[x] >= val
//   int query(int idx, int l, int r, int val){
//     if(tree[idx] < val){
//       return -1;
//     }
//     if(l == r)return l;
//     int mid  = (l+r)>>1;
//     if(tree[2*idx] >= val)return query(2*idx, l, mid, val);
//     else return query(2*idx+1, mid+1, r, val);
//   }
//   void update(int idx, int l, int r, int pos, int new_val){
//     if(l == r){
//       tree[idx] = new_val;
//       return;
//     }
//     int mid = (l+r)>>1;
//     if(pos <= mid)update(2*idx, l, mid, pos, new_val);
//     else update(2*idx+1, mid+1, r, pos, new_val);
//     tree[idx] = max(tree[2*idx], tree[2*idx +1]);
//   }
// };

// void Solve(){
//   int n,m; cin>>n>>m;

//   vector<int> h(n); for(auto& x : h)cin>> x;

//   vector<int> r(m); for(auto& x : r)cin>> x;
//   segtree sgt;
//   sgt.init(n);
//   sgt.build(h,1, 0,n-1);
//   for(int i =0; i <m;i++){
//     int res = sgt.query(1, 0, n-1, r[i]);
//     if(res == -1){
//       cout << 0 << " ";
//     }else{
//       cout << res+1 << " ";
//       h[res]-=r[i];
//       sgt.update(1, 0, n-1, res, h[res]);
//     }
//   }
// }

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