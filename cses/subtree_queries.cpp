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
    int n; cin>>n;
    int q; cin>>q;
    vector<int> a(n+1);
    for(int i =1;i <=n; i++)cin>>a[i];
    vector<vector<int>> adj(n+1);
    for(int i= 0 ;i <n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> subtree_sz(n+1,0);
    vector<int> preorder;
    function<void(int,int)> dfs = [&](int node, int par){
        subtree_sz[node] = 1;
        preorder.push_back(node);
        for(int adjnode : adj[node]){
            if(par == adjnode)continue;
            dfs(adjnode, node);
            subtree_sz[node] += subtree_sz[adjnode];
        }
    };
    dfs(1,-1);
    assert(preorder.size() == n);
    SegTree sgt(n+1);
    vector<int> b(n+1), inv(n+1);
    for(int i =1;i <= n; i++){
        b[i] =(a[preorder[i-1]]);
        inv[preorder[i-1]] = i;
    }

    sgt.build(b);

    for(int i=0; i <q; i++){
        int c; cin>>c;
        if(c ==1){
            int s,x; cin>>s>>x;
            sgt.update(inv[s],inv[s], x-b[inv[s]]);
            b[inv[s]] = x;
        }else{
            int s; cin>>s;
            cout << sgt.query(inv[s], inv[s]+ subtree_sz[s]-1) << endl;
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
