/**
 *    author: Anicetus_7
 *    created: 2025-09-20 23:08:49
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


int n,m;
int dir[4][2] = {{1,0},{0,1}, {-1,0},{0,-1}};
vector<vector<int>> grid;
vector<vector<int>> vis;

inline bool check(int x, int y){
  return x >=0 && y >=0 && x<n && y < m;
}
int dfs(int x,int y){
  vis[x][y] = 1;
  int sum = 0;
  for(int i = 0; i < 4; i++){
    int nx =x+dir[i][0], ny =y+dir[i][1];
    if(!check(nx, ny))continue;
    if(vis[nx][ny])continue;
    if(grid[nx][ny] <=0)continue;
    sum += dfs(nx, ny);
  }
  return sum + grid[x][y];
}

void Solve(){
  cin>>n>>m;

  grid.assign(n, vector<int>(m,0));
  vis.assign(n, vector<int>(m,0));

  for(int i = 0; i< n; i++)
  {
    for(int j = 0; j< m; j++)
    {
      cin>>grid[i][j];
    } 
  }
  int ans = 0;
  for(int i = 0; i< n; i++)
  {
   for(int j = 0; j< m; j++)
   {
    if(vis[i][j] == 0 && grid[i][j] > 0){
      ans = max(dfs(i,j), ans);
    }
   } 
  }


  cout << ans << endl;
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