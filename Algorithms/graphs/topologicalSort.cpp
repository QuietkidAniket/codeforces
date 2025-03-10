#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    void dfs(int node, const vector<int> adjL[], int vis[], stack<int>& st){
        // lemme do this task
        vis[node] =1;
        // dependency == dfs function call stack == dfs function calling tree/sequence 
        // we need to store the dfs sequence of nodes by using a stack
        // we can trace the dependency when we shall be popping the elements.
        // say, 2 -> 3 -> 4, so dfs(2) -> dfs(3)-> dfs(4) which implies that dfs(4) will be executed first
        // and the stack will be 4->3->2 and while popping the dependency will be 2,3,4
        for(const auto& adjNode : adjL[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adjL, vis, st);
            }
        }
        // need to push the node to stack after DFSing from that specific node and completing all the tasks on which it was dependent
        st.push(node);
    }

    vector<int> topoSortDFS(const vector<int> adjL[], int V){
        int vis[V];
        memset(vis, 0, sizeof(vis));
        stack<int> st;
        for(int i = 0; i< V; i++)
        {
            if(!vis[i]){
                dfs(i, adjL, vis, st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    vector<int> topoSortBFS(const vector<int> adjL[], int V){
        int indegree[V];
        memset(indegree, 0, sizeof(indegree));
        for(int i = 0; i< V; i++)
        {
            for(const auto& adjnode: adjL[i]){
                indegree[adjnode]++;
            }
        }
        queue<int> q;
        for(int i = 0; i< V; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(const auto& adjnode :adjL[node]){
                indegree[adjnode]--;
                if(!indegree[adjnode])q.push(adjnode);
            }
        }
        return ans;
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

    auto ans = obj.topoSortBFS(adjL, n);
    for(int i = 0; i< n; i++)
    {
        cout << ans[i] << ", "; 
    }
    cout << '\n';
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