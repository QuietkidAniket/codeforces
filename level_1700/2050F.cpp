/**
 *    author: Anicetus_7
 *    created: 2025-10-27 18:14:03
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


// GCD Segment Tree
// Supports Point Update & Range GCD Queries
const int M = 200005; // Maximum array size
int seg[4 * M];
int a[4*M];

void build(int l, int r, int pos) {
  if (l == r) {
    seg[pos] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, pos * 2);
  build(mid + 1, r, pos * 2 + 1);
  seg[pos] = __gcd(seg[pos * 2], seg[pos * 2 + 1]);
}

// Set value at index 'q_idx' to 'qval'
void update(int l, int r, int pos, int q_idx, int qval) {
  if (l == r) {
    seg[pos] = qval;
    return;
  }
  int mid = (l + r) / 2;
  if (q_idx <= mid) {
    update(l, mid, pos * 2, q_idx, qval);
  } else {
    update(mid + 1, r, pos * 2 + 1, q_idx, qval);
  }
  seg[pos] = __gcd(seg[pos * 2], seg[pos * 2 + 1]);
}

// Query the GCD of elements in range [ql, qr]
int query(int l, int r, int pos, int ql, int qr) {
  if (ql > r || qr < l) return 0; // 0 is the identity for GCD (gcd(x,0)=x)
  if (ql <= l && qr >= r) return seg[pos];
  
  int mid = (l + r) / 2;
  int left_res = query(l, mid, pos * 2, ql, qr);
  int right_res = query(mid + 1, r, pos * 2 + 1, ql, qr);
  
  if (left_res == 0) return right_res;
  if (right_res == 0) return left_res;
  return __gcd(left_res, right_res);
}


void Solve(){
  int n ;cin>>n;
  int q; cin>>q;
  int prev;cin>>prev;
  for(int i=1;i<n;i++){
    int x; cin>>x;
    a[i-1] = abs(prev-x);
    prev = x;
  } 
  if(n > 1)build(0, n-2, 1);
  else{
    for(int i=0;i<q;i++){
      int l, r;
      cin>>l>>r;
      cout << 0 << " ";
    }
    cout << endl;
    return;
  }

  for(int i=0;i<q;i++){
    int l, r;
    cin>>l>>r;
    cout << query(0, n-2, 1, l-1, r-2) << " ";
  }
  cout << endl;
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