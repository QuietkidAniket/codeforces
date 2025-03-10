#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        const int direction[4][2] = {{1,0}, {-1,0} , {0,1}, {0,-1}};
        inline bool check(int row, int col, int m, int n){
            return row>=0 && col >=0 && row<m && col<n;
        }
        void dfs(int row, int col, vector<vector<int>>& vis ,const vector<vector<int>>& matrix, vector<pair<int,int>>& vec, int row0, int col0){
            int m = matrix.size(), n = matrix[0].size();
            vis[row][col] = 1;
            vec.push_back({ row- row0, col -col0 });
            for(int i = 0; i < 4;i++){
                int nrow = direction[i][0], ncol = direction[i][1];
                if(check(nrow, ncol, m,n ) && vis[nrow][ncol] == 0 && matrix[nrow][ncol] == 1)
                {
                    dfs(row, col, vis, matrix, vec, row0, col0);
                }
            }
        }

        auto Islands(const vector<vector<int>>& matrix){
            int m = matrix.size(), n = matrix[0].size(), count {0};
            // initialising the vis to all zeros
            vector<vector<int>> vis(m, vector<int>(n,0));
            set<vector<pair<int,int>>> st;
            for(int row  = 0; row < m; row++){
                for(int col = 0; col < n; col++){
                    vector<vector<int>> vec;
                    if(!vis[row][col] && matrix[row][col] == 1){
                        vector<pair<int,int>> vec;
                        dfs(row, col, vis, matrix, vec, row, col);
                        st.insert(vec);
                    }
                }
            }
            return st.size();
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
    auto st = obj.Islands(arr);
    cout << st<<" \n";
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