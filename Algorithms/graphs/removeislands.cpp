#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGEJUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}

const int direction[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

inline bool check(int row, int col, int m, int n){
    return row>=0 && col >=0 && row<m && col <n;
}

bool dfs(int row, int col, int m, int n,const vector<vector<int>>& grid, vector<vector<bool>>& vis, stack<pair<int,int>>& stk){
    cout << "[" << row << "," << col <<"] -> " << grid[row][col] << '\n';
    vis[row][col] = true;
    bool flag= false;
    for(int i = 0;i < 4; i++){
        int nrow = row + direction[i][0];
        int ncol = col + direction[i][1];
        if(check(nrow, ncol, m , n) && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
            if(!dfs(nrow, ncol, m , n, grid, vis, stk))flag = true;
        }else if(!check(nrow, ncol, m, n))flag = true;
    }
    stk.push({row, col});
    return !flag;
}

void solve(){
    int m, n;
    cin>>m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for(int i = 0; i< m; i++){for(int j = 0; j< n; j++){cin>> arr[i][j];}}

    vector<vector<bool>> vis(m , vector<bool>(n,false));
    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            if(!vis[row][col] && arr[row][col] == 1){
                stack<pair<int,int>> stk;
                if(!dfs(row, col, m, n, arr, vis, stk) ){
                    while(!stk.empty()){
                        arr[stk.top().first][stk.top().second] = 0;
                        stk.pop();
                    }
                }
            }
        }
    }

    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++)cout << arr[row][col] << " "; 
        cout << '\n';
    }
}