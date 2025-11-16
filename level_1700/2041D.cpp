/**
 *    author: Anicetus_7
 *    created: 2025-10-27 19:14:53
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int direction[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void Solve(){
  int n, m; cin>>n>>m;
  char grid[n][m];
  auto check = [&](int r, int c){
    return r >= 0 && c >=0 && r< n && c < m;
  };
  int dp[n][m][4][4];
  queue<array<int,4>> q;
  for(int i =0;i <n ;i++){
    for(int j=0; j <m; j++){
      for(int k = 0; k <4; k++){
        for(int l = 0; l <4; l++){
          dp[i][j][k][l] = INF;
        }
      }
    }
  }

  for(int i =0 ;i < n; i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j]; 
      if(grid[i][j] == 'S'){
        q.push({i,j, 0,0});
        dp[i][j][0][0 ] =0;
      }
    }
  }
  int ans = INF;
  while(!q.empty()){
    auto [r,c, dir, len] = q.front(); q.pop();

    if(grid[r][c] == 'T'){
      ans = min(ans, dp[r][c][dir][len]);
    }

    for(int i = 0;i <4; i++){
      int nr = r + direction[i][0];
      int nc = c + direction[i][1];
      int nlen  = len*(dir == i) + 1;
      if(nlen >=4 )continue;
      if(!check(nr, nc))continue;
      if(grid[nr][nc] == '#')continue;
      if(dp[nr][nc][i][nlen] != INF)continue;
      dp[nr][nc][i][nlen] = dp[r][c][dir][len] +1;
      q.push({nr, nc, i, nlen});
    }
  }
  cout << (ans==INF? -1:  ans)<< endl;
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