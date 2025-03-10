#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void bfs(int row, int col, vector<vector<int>>& vis ,const vector<vector<int>>& matrix){
            vis[row][col] = 1;
            int m = matrix.size(), n = matrix[0].size();
            queue<pair<int, int>> q;
            // push the first element so that we can proceed
            q.push({row, col});
            // till the queue becomes empty, discover all the nodes of the island linked with the first node
            while(!q.empty()){
                int row = q.front().first, col = q.front().second;
                q.pop();

                // check all the 8 "1-neighbours" 
                for(int delrow = -1; delrow <= 1; delrow++){
                    for(int delcol = -1; delcol <= 1; delcol++){
                        // get the current neighbour of interest
                        int nrow = row+delrow, ncol = row+delcol;
                        
                        // if neighbours are a apart of the island, update vis and add them to the queue
                        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol] == 0 && matrix[nrow][ncol] == 1){
                            vis[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                        }
                    }    
                }   
            }
        }  

        auto noOfIslands(const vector<vector<int>>& matrix){
            int m = matrix.size(), n = matrix[0].size(), count {0};
            // initialising the vis to all zeros
            vector<vector<int>> vis(m, vector<int>(n,0));
            for(int row  = 0; row < m; row++){
                for(int col = 0; col < n; col++){
                    if(!vis[row][col] && matrix[row][col] == 1){
                    bfs(row, col, vis, matrix);
                    count++;
                    }
                }
            }
            return count;
        }
};


void solve(){
    Solution obj;
    // string exp;
    // while( (cin >> exp) )
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
    cout << obj.noOfIslands(arr) <<'\n';
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