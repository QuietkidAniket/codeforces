/**
 *    author: Anicetus_7
 *    created: 2025-11-29 18:38:40
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// Sum Segment Tree with Lazy Propagation
// Supports Range Add & Range Sum Queries
const int M = 200005; // Maximum array size
int seg[4 * M];
int lazy[4 * M];
vector<int> a;

void build(int l, int r, int pos) {
  if (l == r) {
    seg[pos] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, pos * 2);
  build(mid + 1, r, pos * 2 + 1);
  seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}

void push(int l, int r, int pos) {
  if (lazy[pos] == 0) return;
  // Add lazy value times the number of elements in the range
  seg[pos] += lazy[pos] * (r - l + 1);
  if (l != r) {
    lazy[pos * 2] += lazy[pos];
    lazy[pos * 2 + 1] += lazy[pos];
  }
  lazy[pos] = 0;
}

// Add 'qval' to all elements in range [ql, qr]
void update(int l, int r, int pos, int ql, int qr, int qval) {
  push(l, r, pos);
  if (ql > r || qr < l) return;
  if (ql <= l && qr >= r) {
    lazy[pos] += qval;
    push(l, r, pos);
    return;
  }
  int mid = (l + r) / 2;
  update(l, mid, pos * 2, ql, qr, qval);
  update(mid + 1, r, pos * 2 + 1, ql, qr, qval);
  
  // Recalculate sum after updating children
  push(l, mid, pos * 2);
  push(mid + 1, r, pos * 2 + 1);
  seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}

// Query the sum of elements in range [ql, qr]
int query(int l, int r, int pos, int ql, int qr) {
  push(l, r, pos);
  if (ql > r || qr < l) return 0; // 0 is the identity for sum
  if (ql <= l && qr >= r) return seg[pos];
  
  int mid = (l + r) / 2;
  int left_res = query(l, mid, pos * 2, ql, qr);
  int right_res = query(mid + 1, r, pos * 2 + 1, ql, qr);
  return left_res + right_res;
}

void Solve(){
  int n; cin>>n;  
  
  
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