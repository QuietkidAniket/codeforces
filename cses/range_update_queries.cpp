/**
 *    author: Anicetus_7
 *    created: 2025-09-13 16:59:04
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct SegTreeSum {
  int n;
  vector<int> tree, lazy;

  void init(int sz) {
    n = sz;
    tree.assign(4*n, 0);
    lazy.assign(4*n, 0);
  }

  void build(vector<int>& arr, int idx, int l, int r) {
    if (l == r) { tree[idx] = arr[l]; return; }
    int mid = (l + r) / 2;
    build(arr, 2*idx, l, mid);
    build(arr, 2*idx+1, mid+1, r);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
  }

  void build(vector<int>& arr) { build(arr, 1, 0, n-1); }

  void push(int idx, int l, int r) {
    if (lazy[idx] != 0) {
      tree[idx] += (r - l + 1) * lazy[idx];
      if (l != r) {
        lazy[2*idx] += lazy[idx];
        lazy[2*idx+1] += lazy[idx];
      }
      lazy[idx] = 0;
    }
  }

  void update(int idx, int l, int r, int ql, int qr, int val) {
    push(idx, l, r);
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) { lazy[idx] += val; push(idx, l, r); return; }
    int mid = (l + r) / 2;
    update(2*idx, l, mid, ql, qr, val);
    update(2*idx+1, mid+1, r, ql, qr, val);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
  }

  int query(int idx, int l, int r, int ql, int qr) {
    push(idx, l, r);
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return tree[idx];
    int mid = (l + r) / 2;
    return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
  }

  void update(int l, int r, int val) { update(1, 0, n-1, l, r, val); }
  int query(int l, int r) { return query(1, 0, n-1, l, r); }
};

void Solve(){
  int n, q; cin>>n>>q;
  vector<int> a(n);
  for(auto& x : a)cin>> x;

  SegTreeSum sgt;
  sgt.init(n);
  sgt.build(a);

  while(q--){
    int c; cin>>c;

    if(c == 1){
      int l,r, u; cin>>l>>r>>u;
      sgt.update(l-1,r-1,u);
    }else{
      int k; cin>>k;
      cout << sgt.query(k-1,k-1)<<endl;
    }
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