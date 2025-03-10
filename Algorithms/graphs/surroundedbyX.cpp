#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int direction[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    inline bool check(int row, int col, int m, int n){
        return row>=0 && col >=0 && row<m && col <n;
    }

    // we check if there is any side of the node is not surrounded by X
    bool dfs(int row, int col, vector<vector<int>> matrix, vector<vector<int>>& vis){
        vis[row][col] = 1;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0 ; i < 4; i++){
            // get the adjacent node
            int nrow=  row+direction[i][0], ncol = col + direction[i][1];

            // if the adjacent node is unvisited and is '0'
            if(check(nrow, ncol, m, n) && vis[nrow][ncol] != 1  && matrix[nrow][ncol]==48){
                    if(!dfs(nrow, ncol, matrix, vis))return false;
            }
            // if the adjacent node is outside the matrix and the given component is not surrounded by X atleast on one side
            else if(!check(nrow, ncol, m, n)){
                return false;
            }
        }
        // if none of the adjacent nodes are outside the matrix
        return true;
    }

    int surroundedbyX(vector<vector<int>> matrix){
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> vis(m , vector<int>(n, 0));
        int count {0};

        for(int row = 0 ;row < m;row++){
            for(int col = 0; col < n; col++){
                // for each separate components
                if(!vis[row][col] && matrix[row][col] == 48){
                    vis[row][col] = 1;
                    if(dfs(row, col, matrix, vis)){
                        count++;
                    }
                }
            }
        }
        return count;
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
        char c;
        cin>> c;
        matrix[i][j] = (int) c;
     }   
    }

    auto ans = obj.surroundedbyX(matrix);
    cout << ans << '\n';
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