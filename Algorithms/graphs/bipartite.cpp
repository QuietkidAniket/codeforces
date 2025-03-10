#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    bool dfs(int node, const vector<int> adjL[], int vis[], int color = 0 ){
        vis[node]= color;

        for(const auto& adjacentnode :  adjL[node]){
            if(vis[adjacentnode] == -1){
                if(!dfs(adjacentnode, adjL, vis, 1-color))return false;
            }else if(vis[adjacentnode] != 1-color)return false;
        }
        return true;
    }

    bool bfs(int node, const vector<int> adjL[], int vis[]){
        vis[node] = 0;
        queue<int> q;
        q.push(node);
        int flag = false;
        while(!q.empty()){
            int node = q.front() , color = 1-vis[node];
            q.pop();
            for(const auto& adjacentNode : adjL[node]){
                if(vis[adjacentNode] == -1){
                    vis[adjacentNode] = color;
                    q.push(adjacentNode);
                }else if(vis[adjacentNode] != color)flag = true;
            }
        }
        return !flag;
    }

    bool isBipartite(vector<int> adjL[], int V){
        int vis[V];
        memset(vis, -1, sizeof(vis));

        // traverse through all the disconnected components
        for(int node= 0; node< V; node++){
            if(vis[node] == -1){
                if(!dfs(node,adjL, vis))return false;
            }
        }
        return true;
    }
};


void solve(){
    Solution obj;
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i< n; i++)
    {   
        for(int j = 0; j< n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> adjL[n];
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            if(arr[i][j] && i != j){
                adjL[i].emplace_back(j);
                adjL[j].emplace_back(i);
            }
        }   
    }

    auto st = obj.isBipartite(adjL, n);
    cout << (st?"true":"false") <<" \n";
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