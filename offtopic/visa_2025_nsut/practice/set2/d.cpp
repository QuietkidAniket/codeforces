/**
 *    author: Anicetus_7
 *    created: 2025-09-30 22:16:04
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int dir[2][2] = {{1,0}, {0,1}};

bool check(int x, int y, int m, int n){
    return x >=0 && y >=0 && x < m && y < n;
}


// 0 = unvisited, 1 = visiting (recursion stack), 2 = processed safe
int dfs(int r, int c, vector<vector<int>>& grid, map<pair<int,int>, pair<int,int>>& teleport, vector<vector<int>>& state) {
    int m = grid.size(), n = grid[0].size();
    if(r == m-1 && c == n-1) return 1;      // reached destination
    if(state[r][c] == 1) return -1;        // cycle detected
    if(state[r][c] == 2) return 0;         // already processed safe

    state[r][c] = 1; // mark as visiting

    // Teleporter
    if(teleport.find({r,c}) != teleport.end()) {
        auto [nr, nc] = teleport[{r,c}];
        if(grid[nr][nc] != -1) {
            int res = dfs(nr, nc, grid, teleport, state);
            if(res != 0) return res; // propagate 1 or -1
        }
    }

    // Normal moves
    for(int i = 0; i < 2; i++){
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if(check(nr, nc, m, n) && grid[nr][nc] != -1){
            int res = dfs(nr, nc, grid, teleport, state);
            if(res != 0) return res;
        }
    }

    state[r][c] = 2; // mark safe
    return 0;        // dead end
}

void Solve(){
    int m,n,l;
    cin >> m >> n >> l;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    map<pair<int,int>, pair<int,int>> teleport;
    for(int i = 0; i < l; i++){
        int x,y,h,k;
        cin >> x >> y >> h >> k;
        teleport[{x,y}] = {h,k};
    }

    vector<vector<int>> state(m, vector<int>(n, 0));
    int ans = dfs(0,0,grid,teleport,state);
    if(ans == 1) cout << 1 << endl;
    else if(ans == -1) cout << -1 << endl;
    else cout << -2 << endl;
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}