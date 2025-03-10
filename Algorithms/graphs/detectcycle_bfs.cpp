#include <bits/stdc++.h>
using namespace std;
class Solution{
    private:
        bool detect(int src, const vector<int> adj[], int vis[]){
            vis[src]= 1;
            queue<pair<int,int>> q;
            q.push({src, -1});
            while(!q.empty()){
                int node = q.front().first;
                int parent= q.front().second;
                q.pop();
                for(const auto& adjacentNode : adj[node])
                {   
                    if(!vis[adjacentNode]){
                        vis[adjacentNode] = 1;
                        q.push({adjacentNode, node});
                    }
                    // if its visited by someone else, then a cycle is formed because more than one node tries to visit this when starting from the same node
                    else{
                        return true;
                    }
                }
            }
            return false;
        }
    public:
        bool isCycle(const int V, const vector<int> adj[]){
            int vis[V];
            memset(vis, 0, sizeof(vis));
            for(int i = 0; i< V; i++)
            {   
                // calls detect only if the given node is a part of a component which has not been visited yet
                if(!vis[i])
                if( detect(i,adj, vis))return true;  
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