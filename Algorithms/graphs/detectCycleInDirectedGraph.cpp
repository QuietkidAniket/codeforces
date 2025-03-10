#include <bits/stdc++.h>
using namespace std;

class Solution{
    public: 
    static const int hi;
    bool bfs_TrialToposort(vector<int> adjL[], int V){
        int indegree[V];
        memset(indegree, 0, sizeof(indegree));
        for(int i = 0; i < V;i++){
            for(const auto& adjnode : adjL[i]){ 
                indegree[adjnode]++;
            }
        }
        queue<int> q;
        for(int i = 0; i< V; i++)   
        {
            if(!indegree[i])q.push(i);   
        }
        int count {0};
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            count++;
            for(const auto& adjnode : adjL[node]){
                indegree[adjnode]--;
                if(!indegree[adjnode])q.push(adjnode);
            }
        }
        // if all the nodes are a part of a topological sort => 
        // then all the nodes are a part of a Directed Acyclic Graph
        // else otherwise
        return !(count ==V);
    }

    bool dfs(int node, vector<int> adjL[], int vis[], int pathvis[]){
        vis[node] =1;
        pathvis[node] = 1;
        for(const auto& adjNode : adjL[node])
        {
            if(!vis[adjNode]){
                if(dfs(adjNode, adjL, vis, pathvis))return true;
            }
            // if the node has been visited but not in the path
            else if(vis[adjNode] && !pathvis[adjNode])return true;
        }
        // after completing the traversal till end, we can return to the original node
        // and mark that it is not visiting any path.
        pathvis[node] = 0;
        return false;
    }
    bool detectCycle(vector<int> adjL[], int V){
        int vis[V];
        memset(vis, 0, sizeof(vis));
        int pathvis[V];
        memset(vis, 0, sizeof(pathvis));

        for(int i = 0; i < V;i++){
            if(!vis[i]){
                if(dfs(i, adjL, vis, pathvis)){
                    return true;
                }
            }
        }   
        return false;
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

    auto st = obj.detectCycle(adjL, n);
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