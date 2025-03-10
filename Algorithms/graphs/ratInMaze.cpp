#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int direction[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    const char directions[4] = {'U', 'D', 'R', 'L'};
    inline bool check(int row, int col, int m, int n){
        return row <m && col < n && row>= 0 && col >= 0;
    }   
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<string>& ans, string s){
        vis[row][col] = 1;
        int m =  grid.size(), n = grid[0].size();
        if(row == m-1 && col == n-1){
            ans.push_back(s);
            return;
        }   
        for(int i = 0 ; i < 4; i++){
            int nrow = row + direction[i][0];
            int ncol = col + direction[i][1];
            if(check(nrow, ncol, m, n) && !vis[nrow][ncol] && grid[nrow][ncol]){
                dfs(nrow, ncol, grid, vis, ans, s + directions[i]);
                vis[nrow][ncol] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        vector<string> ans;
        vector<vector<int>> vis(m, vector<int>(n,0));
        dfs(0,0, grid, vis, ans, "");
        return ans;
    }
};