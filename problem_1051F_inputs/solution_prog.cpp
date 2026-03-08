// _______ Author : Anicetus_7 ____________
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(2*1e5)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// Disjoint Set Union

class Disjoint_Set{
private:
    int n;
    vector<int> parent, sz;

public:
    Disjoint_Set(int n){
        this->n = n;
        parent.resize(n+1,0);
        iota(parent.begin(), parent.end(), 0);
        sz.resize(n+1, 1);
    }

    int findPar(int node){
        if(node == parent[node])return node;
        else return parent[node] = findPar(parent[node]);
    }
    void unite(int u, int v){
        int paru = findPar(u);
        int parv = findPar(v);
        if(paru ==parv)return;

        if(sz[paru] > sz[parv]){
            parent[parv] = paru;
            sz[paru] += sz[parv];
        }else{
            parent[paru] = parv;
            sz[parv] += sz[paru];
        }
    }
};

// Minimum Segment Tree
class Segment_Tree{
    private:
  int n;
  vector<pair<int,int>> seg;
  public:
  Segment_Tree(int n){
    this->n = n;
    seg.resize(4*n, {INF, n+1});
  }
  void build(int l, int r, int pos, vector<int>& a){
      if(l == r){
          seg[pos] = {a[l], l};
      }else{
          int mid = (l+r)>>1;
          build(l, mid, 2*pos, a);
          build(mid+1, r, 2*pos+1, a);
          seg[pos] = min(seg[2*pos], seg[2*pos+1]);
      }
  }
  void build(vector<int>& a){
    build(0, n-1, 1, a);
  }
  pair<int,int> query(int pos, int start, int end, int l, int r){
     if(start > end || start > r || end < l)return {INF,n+1};
     if(l <= start && end <= r){
        return seg[pos];
     }
     int mid = (start+end)>>1;
     auto left= query(2*pos, start, mid, l, r);
     auto right = query(2*pos+1, mid+1, end, l, r);
     return min(left, right);
  }
  pair<int,int> query(int l, int r){
    return query(1, 0, n-1, l, r);
  }
};


/**    _______________________SOLVE_______________________  */

void Solve(){
 int n,m; cin>>n>>m;
 vector<tuple<int,int,int>> a(m);
 for(int i =0 ;i < m; i++){
     int u, v, w; cin>>u>>v>>w;
     a[i] = {w,u,v};
 }
 // Kruskal's MST algorithm + special nodes finding
 Disjoint_Set dsu(n+1);

 vector<vector<pair<int,int>>> adj(n+1);        // v,w
 vector<vector<pair<int,int>>> full_adj(n+1);        // v,w
 vector<tuple<int,int,int>> spec(n+1);  // u,v,w
 set<int> special_nodes;
 for(auto& [w, u,v] :  a){
     if(dsu.findPar(u) != dsu.findPar(v)){
        dsu.unite(u, v);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
     }else{
        special_nodes.insert(u);
        special_nodes.insert(v);
        spec.push_back({u,v,w});
     }
    full_adj[u].push_back({v,w});
    full_adj[v].push_back({u,w});
 }


 // euler tour + RMQ for  lca
 vector<int> euler, depth(n+1,0), euler_depth;

 vector<int> inv(n+1, n), firstoc(n+1,n);

 function<void(int,int)> f = [&](int node, int par){
    firstoc[node] = euler.size();
    euler.push_back(node);
    euler_depth.push_back(depth[node]);
    for(auto adjnode : adj[node]){
        if(adjnode.first !=  par){
            depth[adjnode.first] = depth[node] + 1;
            f(adjnode.first, node);
            euler.push_back(node);
            euler_depth.push_back(depth[node]);
        }
    }
 };

 f(1, 0);


 Segment_Tree sgt(euler.size());

 sgt.build(euler_depth);

 auto lca = [&](int u, int v)->int{
    int idx1 = firstoc[u];
    int idx2 = firstoc[v];
    if(idx1 > idx2)swap(idx1, idx2);
    int pos = sgt.query(idx1, idx2).second;
    return euler[pos];
 };
 // end of lca finding

 // calculate the height of the nodes in the MST
 vector<int> h(n+1, 0); // height of the nodes from the root node 1
 function<void(int, int )>  dfs = [&](int node, int par){
    for(auto [adjnode,w] : adj[node]){
        if(adjnode == par)continue;
        h[adjnode] += h[node] + w;
        dfs(adjnode, node);
    }
 };
 dfs(1, 0);


 // Dijkstra over the special nodes

 vector<vector<int>> d;

 auto dij = [&](int root){
    vector<int> dist(n+1,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, root});
    dist[root] = 0;
    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();
        if(dist[node] < d)continue;
        for(auto [adjnode, w] : full_adj[node]){
            if(dist[adjnode] > dist[node] + w){
                dist[adjnode] = dist[node]+ w;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    d.push_back(dist);
 };

 for(int node : special_nodes){
     dij(node);
 }


 // queries
 int q; cin>>q;
 for(int i=0;i < q; i++){
     int u, v; cin>>u>>v;
     int ans =  h[u]+ h[v] - 2*h[lca(u,v)];
     for(int i = 0 ; i < d.size(); i++){
         ans= min(ans, d[i][u]+ d[i][v]);
     }
     cout << ans <<endl;
 }

}


//_______________[MAIN]__________________
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++)
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
