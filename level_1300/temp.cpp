#define ll long long
const int MOD = 1e9 + 7;

class Solution{
private:
  vector<int> parent;
  vector<int> depth;
  vector<vector<int>> adjl;
  void dfs(int node, int par){
    for(int adjnode : adjl[node]){
      if(adjnode != par){
        depth[adjnode] = depth[node] + 1;
        parent[adjnode] = node;
        dfs(adjnode, node);
      }
    }
  }
  int lca(int u ,int v){
    while(u != v){
      if(depth[u] > depth[v])u = parent[u];
      else v = parent[v];
    }
    return u;
  }

  ll modPow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
  }
  
  public:
  vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    int n = edges.size()+1;
    adjl.resize(n+1, vector<int>());
    parent.resize(n+1,0);
    depth.resize(n+1,0);
    for(const auto& edge :  edges){
      int u = edge[0], v= edge[1];
      adjl[u].push_back(v);
      adjl[v].push_back(u);
    }
    dfs(1,0);

    vector<int> ans;
    for(const auto& query : queries){
      int u = query[0], v = query[1];
      int depth_lca = depth[lca(u, v)];
      int edgecount= depth[u] + depth[v] - 2* depth_lca;
      if(edgecount == 0)ans.push_back(0);
      else ans.push_back(modPow(2, edgecount-1));
    }
    return ans;
  }
};
