#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    const int  direction[4][2] = {{1,0}, {-1,0} , {0,1}, {0,-1}};
    inline bool check(int row, int col, int m, int n){
        return row >=0 && row <m && col>=0 && col<n; 
    }

    int rottenOranges(vector<vector<int>>& matrix){
        int m = matrix.size(), n  =matrix[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));
        queue< pair<pair<int, int>,int> > q;

        int countFresh {0};
        for(int i = 0 ;i < m; i++){
        for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 2){
                    q.push({ {i,j}, 0} );
                    vis[i][j] = 2;
                }else if(matrix[i][j] == 1)countFresh++;
            }
        }

        int count {0};
        int time {0};
        while(!q.empty()){
            int row = q.front().first.first, col = q.front().first.second, t = q.front().second;
            q.pop();

            time = max(time, t);
            
            for(int i = 0 ; i < 4; i++){
                int nrow = direction[i][0] + row, ncol = direction[i][1] +col;
                if(check(nrow, ncol, m, n) && vis[nrow][ncol] != 2 && matrix[nrow][ncol] == 1 ){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }
        }

        // check if any orange has been left to be rotten, if yes then return -1, as we need to rot all oranges
        if(count != countFresh)return -1;
        return time;
    }


};



void solve(){
    Solution obj;
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
    auto ans = obj.rottenOranges(arr);
    cout << ans;
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
