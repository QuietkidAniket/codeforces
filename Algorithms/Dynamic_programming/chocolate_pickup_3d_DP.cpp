#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

class Solution {
  public:
    int find(int i, int j1, int j2, int m, int n, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){
        if(j1 < 0 || j2 < 0 || j1 >=n || j2 >= n)return -1e9;
        if(i == m-1){
            if(j1 == j2)return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        int max_i = -1e9;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int value = find(i+1, j1+dj1, j2+dj2, m, n, dp, grid);
                if(j1 == j2){
                    max_i = max(max_i, grid[i][j1] + value );
                }else{
                    max_i = max(max_i, grid[i][j1] + grid[i][j2] + value);
                }
            }    
        }
        return dp[i][j1][j2] = max_i;
    }
    int solve(int m, int n, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return find(0, 0, n-1, m,n , dp, grid);
    }
};

//{ Driver Code Starts.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }

    Solution obj;
    cout << obj.solve(n, m, grid) << "\n";


    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}
// } Driver Code Ends

/*
Sample input:
4 3
3 1 1
2 5 1
1 5 5
2 1 1

output:
24
*/

