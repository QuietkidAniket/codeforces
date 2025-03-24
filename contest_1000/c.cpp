#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;


void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
    vis[node] = true;
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(x, adj, vis);
        }
    }
}


void Solve(){
    int n;
    cin>> n;
    vector<int> indegree(n+1, 0);
    indegree[0] = INT_MIN;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
    }
    int node1 = max_element(indegree.begin(), indegree.end()) - indegree.begin();
    indegree[node1] = INT_MIN;
    for(auto x : adj[node1]){
        indegree[x]--;
    }
    adj[node1].clear();


    int node2 = max_element(indegree.begin(), indegree.end()) - indegree.begin();
    indegree[node2] =INT_MIN;
    for(auto x : adj[node2]){
        indegree[x]--;
    }
    adj[node2].clear();
    
    int n_components = 0;
    vector<bool> vis(n+1, false);
    for(int node = 1; node <= n; node++){
        if(node == node1 || node == node2)continue;
        if(!vis[node]){
            n_components++;
            dfs(node, adj, vis);
        }
    }
    cout << n_components;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    int tt = clock();
    #endif
    
    int t = 1;
    if(multi)cin>> t;
    while(t--){
    Solve();
    cout << endl;
    }
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}