#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> vis){
    // we visit the node and its unvisited neighbours
    vis[node] = 1;
    for(auto it  : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

void solve(){
    int n, m;

    cin>> n >>m;
    vector<pair<int,int>> roads(m);
    // undirected graph
    vector<int> adj[n];
    for(int i =0; i <m; i++){
        int x ,y;
        cin>> x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    vector<int> vis(n);
    vis = {0};
    int count {0};
    // iterate through the nodes
    for(int i = 0 ; i< n; i++){
        // if any unvisited nodes
        if(!vis[i]){
            count++;
            
            // visit the node and its univisited neighbours
            dfs(i ,adj,vis);
        }
    }


    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    solve();
    
    
    return 0;
}