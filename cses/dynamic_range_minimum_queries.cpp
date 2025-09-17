/**
 *    author: Anicetus_7
 *    created: 2025-09-12 00:41:29
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct segtree{
  vector<int> tree;
  int sz;
  void init(int n){
    sz = 1;
    while(sz < n) sz <<= 1;
    tree.assign(2*sz, 1e9);
  }
  void set(int i, int v){
    int x = i + sz;
    tree[x] = v;
    for(x >>= 1; x; x >>= 1){
      tree[x] = min(tree[2*x], tree[2*x+1]);
    }
  }

  /** @return range minimum query on [l, r) */
  int get(int l, int r){ 
    int res = 1e9;
    l += sz; r += sz;
    while(l < r){
      if(l & 1) res = min(res, tree[l++]);
      if(r & 1) res = min(res, tree[--r]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};



void Solve(){
  int n,q; cin>> n >> q;

  vector<int> a(n); for(auto& x : a)cin>> x;
  // Sqrt_decomposition sd;
  // sd.init(a);

  segtree st;
  st.init(n);

  for(int i = 0 ; i < n; i++){
    st.set(i,a[i]);
  }

  for(int i =0 ; i < q; i++){
    int c; cin>>c;
    
    if(c == 1){
      int k, u; cin>>k>>u;
      st.set(k-1, u);
    }else{
      int l,r; cin>>l>>r;
      cout << st.get(l-1, r) <<endl;
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

