#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    bool dfs(int node, vector<int> adjL[], int vis[], int pathvis[], int check[]){
        vis[node] = 1;
        pathvis[node] =1;
        check[node] = 0;
        for(const auto& adjnode: adjL[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode,adjL, vis, pathvis, check)){
                    check[node] = 0;
                    return true;
                }
            }
            // visited but path set 1 => then cycle detected
            else if(pathvis[adjnode]==1){ 
                check[node] = 0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node] = 0;
        return false;
    }
    vector<int> detectEssentialNode(vector<int> adjL[], int V){
        int vis[V];
        memset(vis, 0, sizeof(vis));
        int pathvis[V];
        memset(pathvis, 0, sizeof(pathvis));
        int check[V];
        memset(check, 0, sizeof(check   ));
        vector<int> safenodes;
        for(int i = 0; i< V; i++)
        {
            if(!vis[i]){
                dfs(i, adjL, vis, pathvis, check);
            }
        }
        for(int i = 0; i < V;i++){
            if(check[i] == 1)safenodes.emplace_back(i);
        }
        return safenodes;
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

    auto st = obj.detectEssentialNode(adjL, n);

    for(const auto& x : st)
    {
        cout << x << '\n';
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