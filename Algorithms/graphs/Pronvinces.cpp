#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    inline void dfs(int node, vector<int> adjLs[], int vis[]){  
        vis[node] = 1;
        for(const auto& adj_node: adjLs[node])
        {
            if(!vis[adj_node]){
                dfs(adj_node, adjLs, vis);
            }
        }
    }

    // adjacency matrix = adjM , number of vertices = V
    int numberOfProvinces(vector<vector<int>> adjM, int V){
        // creating the adjacency list
        vector<int> adjLs[V];
        for(int i = 0; i< V; i++)
        {
         for(int j = 0; j< V; j++)
         {
            if(i != j && adjM[i][j]== 1){
                adjLs[i].emplace_back(j);
                adjLs[j].emplace_back(i);
            }
         }
        }


        // counting the number of Provinces
        int count {0};
        int vis[V];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < V; i++){
            // if not visited
            if(!vis[i]){
                dfs(i, adjLs, vis);
                count++;
            }
        }
        return count;
    } 

    void dfs_with_province(const int node, vector<int> adjLs[], int vis[], vector<int>& connected_nodes){
        vis[node] = 1;
        connected_nodes.emplace_back(node);
        for(const auto& it : adjLs[node]){
            if(!vis[it]){
                dfs_with_province(it, adjLs, vis, connected_nodes);
            }
        }
    }

    vector<vector<int>> AllProvinces(vector<vector<int>> adjM, int V){
        vector<int> adjLs[V];
        
        for(int i = 0; i< V; i++)
        {
            for(int j = 0; j< V; j++)
            {
                if(adjM[i][j] && i != j){
                    adjLs[i].emplace_back(j);
                    adjLs[j].emplace_back(i);
                }
            }       
        }

        vector<vector<int>> Provinces;
        int vis[V];
        memset(vis, 0 , sizeof(vis));
        for(int i = 0 ; i < V; i++){
            if(!vis[i]){
                vector<int> connected_nodes;
                dfs_with_province(i, adjLs, vis, connected_nodes);
                Provinces.emplace_back(connected_nodes);
            }
        }
        return Provinces;

    }
};



void solve(){
    Solution obj;
    int V;
    cin >>V;
    vector<vector<int>> adjM(V);
    for(int i = 0; i< V; i++)
    {      
        for(int j = 0; j< V; j++)
        {   
            int x;
            cin>> x;
            adjM[i].emplace_back(x);
        }
    }
    
    auto Provinces = obj.AllProvinces(adjM, V);
     for(const auto& province : Provinces)
        {
            for(const auto& node : province){
                cout << node << ", ";
            }
            cout << '\n';
        }

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