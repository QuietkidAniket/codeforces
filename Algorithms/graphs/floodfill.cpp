#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    inline bool check(int row, int col, int m, int n)
    {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    const int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int row, int col, const int color, const int target_color, vector<vector<int>> &vis, vector<vector<int>> &matrix)
    {
        vis[row][col] = 1;
        int m = matrix.size(), n = matrix[0].size();
        matrix[row][col] = target_color;
        for (int i = 0; i < 4; i++)
        {
            int delrow = direction[i][0], delcol = direction[i][1];
            int nrow = delrow + row, ncol = delcol + col;
            if (check(nrow, ncol, m, n) && !vis[nrow][ncol] && matrix[nrow][ncol] == color)
            {
                dfs(nrow, ncol, color, target_color, vis, matrix);
            }
        }
    }

    vector<vector<int>> floodFill(const vector<vector<int>> &matrix, int start_row, int start_col, int target_color)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        auto matrix2(matrix);
        int color = matrix2[start_row][start_col];

        for (int i = 0; i < 4; i++)
        {
            int delrow = direction[i][0], delcol = direction[i][1];
            int nrow = delrow + start_row, ncol = delcol + start_col;
            if (check(nrow, ncol, m, n) && !vis[nrow][ncol] && matrix2[nrow][ncol] == color)
            {
                dfs(nrow, ncol, color, target_color, vis, matrix2);
            }
        }
        return matrix2;
    }
};

void solve()
{
    Solution obj;
    // string exp;
    // while( (cin >> exp) )
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int x, y, color;
    cin >> x >> y >> color;
    auto ans = obj.floodFill(arr, x, y, color);
    for (const auto &row : ans)
    {
        for (const auto &x : row)
        {
            cout << x << ' ';
        }
        cout << '\n';
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