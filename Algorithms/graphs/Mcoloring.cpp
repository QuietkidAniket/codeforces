#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int node, vector<int> adjl[], vector<int>& vis,int m){
        
        unordered_map<int, bool> used;
        // look for what the adjcacent colors are out of the m colors
        for(const int adjnode : adjl[node]){
            if(vis[adjnode]){
                used[vis[adjnode]] = true;
            }
        }
        // assign a color which is not there in adjcacent nodes
        for(int color = 1; color<=m ; color++){
            if(!used[color]){
                vis[node] = color;
                break;
            }
        }
        // if no such color exist then just simply conclude that m coloring is not possible
        if(!vis[node])return false;
        // dfs through remaining unvisited nodes
        for(const auto& x : adjl[node]){
            if(!vis[x]){
                if(!dfs(x, adjl, vis, m))return false;
            }
        }
        return true;
    }
    bool graphColoring(int n, vector<pair<int, int>>& edges, int m) {
        vector<int> adjl[n];
        vector<int> vis(n,0);
        for(const auto& edge : edges){
            adjl[edge.first].push_back(edge.second);
            adjl[edge.second].push_back(edge.first);
        }
        // dfs through unvisited nodes
        for(int i= 0; i < n;i++){
            if(!vis[i]){
                if(!dfs(i, adjl, vis, m)) return false;
            }
        }
    
        return true;
    }
    

};
