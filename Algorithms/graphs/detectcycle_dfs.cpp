#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool dfs(int node, int parent, vector<int> adjL[], int vis[]){
        vis[node] = 1;
        for(const auto& adjacentnode : adjL[node]){
            if(!vis[adjacentnode]){
                vis[adjacentnode] = 1;
                return dfs(adjacentnode, node, adjL, vis);
            }else{
                return true;
            }
        }
        return false;
    }

    bool isCycle(const int V, vector<int> adjL[]){
        int vis[V];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < V;i++){
            // if the node is not visited, then the component has also not been 
            // visited... visit the unvisited component's node
            if(!vis[i]){
                if(dfs(i, -1, adjL, vis))return true;
            }
        }
        return false;
    }

};


void solve(){
    Solution obj;

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    solve();
    
    
    return 0;
}