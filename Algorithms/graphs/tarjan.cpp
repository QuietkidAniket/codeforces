#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>& adjl, vector<int>& vis, vector<int>& tim, vector<int>& low, vector<vector<int>>& bridges){
        vis[node] = 1;
        tim[node] = low[node] = timer;
        timer++;

        for(const auto& adjnode : adjl[node]){
            // if the dfs caller is encountered then skip updating the low[]
            if(adjnode == parent)continue;
            if(!vis[adjnode]){
                dfs(adjnode, node, adjl, vis, tim, low, bridges);
                // check for minimum low among the neighbours and replace
                low[node] = min(low[node], low[adjnode]);
                // dfs(a) -> dfs(b);
                // if tim[a] < low[b] then bridge
                if(tim[node] < low[adjnode]){
                    bridges.push_back({adjnode, node});
                }
            }else{
                // check for minimum low among the neighbours and replace
                low[node] = min(low[node], low[adjnode]);
            }
        }
    }
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {        
        vector<int> tim(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        vector<int> vis(n, 0);
        vector<vector<int>> adjl(n);
        for(const auto& edge: connections){
            adjl[edge[0]].push_back(edge[1]);
            adjl[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, adjl, vis, tim, low, bridges);
        return bridges;
    }
};