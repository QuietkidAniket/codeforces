#include <bits/stdc++.h>
using namespace std;

/*
* 1 -> land cell, 0 -> sea
* Find the number of land cells in grid for which we cannot walk off the 
boundary of the grid in any number of moves
* that is
* which are completely surrounded by 0
*/

class Solution{
    public:
    int direction[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    inline bool check(int row, int col, int m, int n){
        return row>=0 && col>=0 && row<m && col < n;
    }

    bool bfs(int row, int col, vector<vector<int>> matrix, vector<vector<int>>& vis){
        vis[row][col]= 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int m = matrix.size(), n= matrix[0].size();
        bool flag = false;
        while(!q.empty()){
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(int i = 0; i < 4;i++){
                int nrow = direction[i][0] + row, ncol = direction[i][1] + col;
                if(check(nrow, ncol, m,n) && vis[nrow][ncol] == 0 && matrix[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                } else if( !check(nrow, ncol, m, n) ){
                    flag = true;
                }
            }
        }
        if(flag)return false;
        return true;
    }

    int noOfEnclaves(vector<vector<int>> matrix){
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int count {0};

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n ;col++){
                // call bfs for only the separate components which have not been visited
                if(!vis[row][col] && matrix[row][col] == 1){
                    vis[row][col] =1;
                    if(bfs(row, col, matrix, vis))count++;
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
        cin >> matrix[i][j];
     }   
    }

    auto ans = obj.noOfEnclaves(matrix);
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