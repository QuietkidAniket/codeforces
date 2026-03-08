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

void Solve(){
    int n,q; cin >> n>>q;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++){
        int u, v; cin >> u >> v;
        if(u==0 && v==0) continue;
        adj[i].push_back(u);
        adj[i].push_back(v);
    }
    vector<int> dp(n+1, 0); // stores the actual path cost from node to node 0
    vector<vector<int>> anc(n+1, vector<int>(20, 0)); // 2^jth ancestor of node i
    vector<int> euler; // stores the euler tour of the tree
    vector<int> mn(n+1,0); // stores the first occurence index in the euler tour of the node

    // computes the total cost from node to 0, also computes the euler tour
    function<void(int)> f = [&](int node){
        mn[node] = (int)euler.size();
        euler.push_back(node);
        for(auto adjnode: adj[node]){
            dp[adjnode] = (dp[node]+dp[adjnode]+1);
            f(adjnode);
            euler.push_back(node);
         }
    };
    // computes the subtree cost rooted by node, also computes the binary lifting
    function<void(int, int)> f2 = [&](int node, int par){
        anc[node][0] = par;
        for(int depth = 1; depth < 20; depth++){
            anc[node][depth] = anc[anc[node][depth-1]][depth-1];
        }
        if(adj[node].empty())return;
        int sum = 0;
        for(auto adjnode: adj[node]){
            if(!adjnode)continue;
            f2(adjnode, node);
            sum += (dp[adjnode]+2);
        }
        dp[node] = sum;
    };

    f2(1,0);
    f(1);
    
    // checks for the ancestor where the target node maybe present
    for(int i =0 ;i < q; i++){
        int v, k; cin>>v>>k;
        int lca = v;
        for(int j =19; j >=0 ;j--){
            if(anc[lca][j] != 0 && dp[v] - dp[anc[lca][j]] <=k)lca = anc[lca][j];
        }
        k -= (dp[v] - dp[lca]);
        // after reaching the ancestor, the subtree should be having the target
        int node = euler[mn[lca] +k];
        cout << node << " ";
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
