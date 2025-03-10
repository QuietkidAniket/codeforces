#include <bits/stdc++.h>
using namespace std;
/*
* NOTE: here we are dealing with Manhattan distance only, i.e., for (x,y) and (a,b), Manhattan dist = |x - a| + |y - b|
*/
class Solution{
    public:
        int direction[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        inline bool check(int row, int col, int m, int n){
            return row>=0 && row<m && col>=0 && col<n;
        }
        vector<vector<int>> nearest(vector<vector<int>> grid){
            int m = grid.size(), n = grid[0].size();
            queue<pair< pair<int,int> ,int>> q;
            // will store the distance of each node from the nearest '1'
            vector<vector<int>> dist(m, vector<int>(n,0));
            // keeps a track of the visited nodes
            vector<vector<int>> vis(m, vector<int>(n, 0));

            // We need to start our BFS traversals from all the '1's
            // hence, go through the grid marking the '1's and pushing those nodes into the queue
            for(int i = 0; i< m; i++)
            {
                for(int j = 0; j< n; j++)
                {   
                    // visit the nodes with value '1' and mark them as visited after adding them to queue
                    if(grid[i][j] ==1){
                        q.push({{i,j}, 0});
                        vis[i][j] = 1;
                        // distance already set to 0 by default in dist vector
                    }
                }
            }
            // BFS through the adjacent nodes and note down how far they are from the nearest ones
            while(!q.empty()){
                int row = q.front().first.first, col = q.front().first.second, distance = q.front().second;
                q.pop();
                // traverse to the adjacent nodes (4 adjacent nodes of each node)
                for(int i = 0 ;i < 4; i++){
                    int nrow = row + direction[i][0], ncol = col + direction[i][1];
                    // if the given node is not marked visited and is a valid node
                    // then push the node int queue and record the distance
                    if(check(nrow, ncol, m, n) && vis[nrow][ncol] == 0){
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, distance+1}); 
                        dist[nrow][ncol] = distance +1;
                    }
                }
            }
            return dist;
        }
};



void solve(){
    Solution obj;
    int m,n;
    cin>> m>>n;
    vector<vector<int>> matrix(m, vector<int>(n,0));
    for(int i = 0; i< m; i++)
    {
     for(int j = 0; j< n; j++)
     {
        cin>> matrix[i][j];
     }   
    }
    auto ans = obj.nearest(matrix);
    for(const auto& row : ans){
        for(const auto& x : row){
            cout << x << ' ';
        }
        cout<< '\n';
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