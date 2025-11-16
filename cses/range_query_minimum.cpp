/**
 *    author: Anicetus_7
 *    created: 2025-09-28 12:57:04
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct SegTreeMin{
  int n;
  vector<int> tree, lazy;

  void init(int sz) {
    n = sz;
    tree.assign(4*n, INF);
    lazy.assign(4*n, 0);
  }

  void build(vector<int>& arr, int idx, int l, int r) {
    if (l == r) { tree[idx] = arr[l]; return; }
    int mid = (l + r) / 2;
    build(arr, 2*idx, l, mid);
    build(arr, 2*idx+1, mid+1, r);
    tree[idx] = min(tree[2*idx], tree[2*idx+1]);
  }

  void build(vector<int>& arr) { build(arr, 1, 0, n-1); }

  void push(int idx, int l, int r) {
    if (lazy[idx] != 0) {
      tree[idx] += lazy[idx];
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
    tree[idx] = min(tree[2*idx], tree[2*idx+1]);
  }

  int query(int idx, int l, int r, int ql, int qr) {
    push(idx, l, r);
    if (qr < l || r < ql) return INF;
    if (ql <= l && r <= qr) return tree[idx];
    int mid = (l + r) / 2;
    return min(query(2*idx, l, mid, ql, qr), query(2*idx+1, mid+1, r, ql, qr));
  }

  void update(int l, int r, int val) { update(1, 0, n-1, l, r, val); }
  int query(int l, int r) { return query(1, 0, n-1, l, r); }
};


void Solve(){
  int n; cin>>n;
  vector<int> a(n); for(auto& x : a)cin>>x;
  SegTreeMin sgt;
  sgt.init(n);
  sgt.build(a);
  int q; cin>>q;
  for(int i = 0; i <q; i++){
    int l,r; cin>>l>>r;
    cout << sgt.query(l, r) << endl;
  }
  
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