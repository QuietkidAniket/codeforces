/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree {
    int n;
    vector<int> seg;
    vector<int> lazy;

    SegTree(int _n) {
        n = _n;
        seg.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
    }

    void push(int l, int r, int pos) {
        if (lazy[pos] == 0) return;
        seg[pos] += lazy[pos] * (r - l + 1);
        if (l != r) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    void build(const vector<int>& a, int l, int r, int pos) {
        if (l == r) {
            seg[pos] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, l, mid, pos * 2);
        build(a, mid + 1, r, pos * 2 + 1);
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
    }

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
        seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
    }

    int query(int l, int r, int pos, int ql, int qr) {
        push(l, r, pos);
        if (ql > r || qr < l) return 0;
        if (ql <= l && qr >= r) return seg[pos];
        int mid = (l + r) / 2;
        return query(l, mid, pos * 2, ql, qr) + query(mid + 1, r, pos * 2 + 1, ql, qr);
    }

    void build(const vector<int>& a) { build(a, 1, n, 1); }
    void update(int ql, int qr, int val) { update(1, n, 1, ql, qr, val); }
    int query(int ql, int qr) { return query(1, n, 1, ql, qr); }
};

void Solve(){
    int n,q; cin>>n>>q;
    vector<int> a(n); for(auto& x : a)cin>> x;
    
    vector<vector<int>> adj(n+1);
    
    for(int i =0; i <n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // sz stores the subtree size;
    // sp[i] stores the path sum till the ith node in preorder
    // preorder[node] maps node to the ith index of preorder
    vector<int> sz(n+1,0), sp, preorder(n+1,0);
    sp.push_back(0);
    function<void(int, int , int)> dfs = [&](int node, int par, int sum){
        sz[node] = 1;
        preorder[node] = sp.size();
        sum += a[node-1];
        sp.push_back(sum);
        for(int adjnode: adj[node]){
            if(adjnode == par)continue;
            dfs(adjnode, node, sum);
            sz[node] += sz[adjnode];
        }
    };
    dfs(1,0, 0);
    SegTree sgt(sp.size());
    sgt.build(sp);
    

    // queries
    for(int i = 0; i < q; i++){
        int c; cin>>c;
        if(c == 1){
            int node; cin>>node; int val; cin>>val;
            int curval = a[node-1];
            int diff = val- curval;
            a[node-1] = val;
            sgt.update(preorder[node], preorder[node] + sz[node]-1, diff);
        }else{
            int node; cin>>node;
            cout << sgt.query(preorder[node], preorder[node]) << endl;
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
