#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void dfs(int node, vector<int> adj[], int vis[], stack<int>& stk){
        vis[node] = 1;
        for(const auto& adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode, adj, vis, stk);
            }
        }
        stk.push(node);
    }
    void dfs2(int node, vector<int> adj[], int vis[]){
        vis[node] = 1;
        for(const auto& adjnode: adj[node]){
            if(!vis[adjnode]){
                dfs2(adjnode, adj, vis);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[]){
        stack<int> stk;
        int vis[V];
        memset(vis, 0, sizeof(vis));
        // 1 > Sort the nodes based on finishing time, O(V+E)
        for(int i = 0 ; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, stk);
            }
        }
        // 2> Reverse the graph and reset the visited array, O(V+E)
        vector<int> adj_rev[V];
        for(int i = 0; i < V; i++){
            vis[i] = 0;
            for(auto& node: adj[i]){
                adj_rev[node].push_back(i);
            }
        }
        // 3> Perform a DFS using the sorted nodes and the reversed graph
        //      while keeping a count of the strongly connected components
        // O(V+E)
        int scc_count = 0;
        while(!stk.empty()){
            int node= stk.top();
            stk.pop();
            if(!vis[node]){
                scc_count++;
                dfs2(node, adj_rev, vis);
            }
            
        }
        return scc_count;

    }
};