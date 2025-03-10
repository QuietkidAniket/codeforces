/* PROBLEM : 
Simultaneous Robots
You are given an N×M grid A. Let (i,j)(i,j) denote the square in the i-th row from the top and the j-th column from the left.
Each square is either empty or blocked, denoted by characters '.' and '#', respectively.
It is guaranteed that (1,1)(1,1) and (N,M)(N,M) are both empty.
Two robots are placed initially together at (1,1)(1,1). The robots move under the following constraints:
Every second, both the robots must each move to an adjacent empty square.
This movement can be done in any of the four directions: up, down, left, or right.

Formally, a robot in (i,j)(i,j) can move to any of 
(i−1,j),(i+1,j),(i,j−1),(i,j+1) as long as the destination cell is free.
Note that the robots choose their movements independently of each other - the only condition is that they must both move.
However, there is one restriction: at any point of time, both robots must not be on the same square.
The only exceptions to this are 
(1,1) and (N,M), which are allowed to contain both simultaneously.
Your goal is to find the minimum time needed for both the robots to be at 
(N,M)
(N,M) simultaneously, or determine if this is not possible under the given constraints.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

bool check(int row, int col, int n, int m){
  return row >= 0 && col >= 0 && row<n && col < m;
}

static const int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
void Solve(){
  int n, m;
  cin>> n>> m;
  vector<vector<char>> grid(n,vector<char>(m));
  for(int i = 0; i< n; i++)
  {
   for(int j = 0; j< m; j++)
   {
    cin>> grid[i][j];
   } 
  }
  // base case/ edge case
  if(!(grid[1][0]=='.' && grid[0][1]=='.' && grid[n-1][m-2]=='.' && grid[n-2][m-1]=='.')){
    cout<<-1;
    return;
  }
  // lets check whether first robot is able to reach n-1 and m-1
  vector<vector<int>> dist(n, vector<int>(m,1e8));
  dist[0][0] = 0;
  queue<pair<int,int>> q;
  q.push({0,0});
  while(!q.empty()){
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    if(row == n-1 &&col == m-1){
      while(!q.empty())q.pop();
      break;
    }
    for(int i = 0; i < 4; i++){
      int nrow = row +dir[i][0];
      int ncol = col +dir[i][1];
      if(!check(nrow, ncol, n, m))continue;
      if(dist[nrow][ncol] == 1e8 && grid[row][col] == '.'){
        dist[nrow][ncol] = dist[row][col] + 1;
        q.push({nrow, ncol});
      }
    } 
  }
  // check whether the n-1,m-1 node had been reached or not
  if(dist[n-1][m-1] == 1e8){
    cout << -1;
    return;
  }

  // back track the path and add the path into a data structure
  vector<pair<int,int>> path;
  int x = n-1, y = m -1, dis= dist[n-1][m-1];
  while(x>0 || y > 0){
    for(int i = 0; i < 4; i++){
      int nx = x - dir[i][0], ny = y - dir[i][1];
      if(!check(nx, ny, n,m))continue;
      if(grid[nx][ny] == '.' && dist[nx][ny] == dis - 1){
        dis--;
        path.push_back({nx,ny});
        x= nx, y = ny;
        break;
      }
    }
  }
  // now make the path hidden for the next robot
  for(const auto& [i,j] : path){
    grid[i][j] = '#';
  }
  grid[0][0] = grid[n-1][m-1] = '.';

  // now the 2nd robot travels the other path if any 
  // lets check whether first robot is able to reach n-1 and m-1
  vector<vector<int>> dist1(n, vector<int>(m,1e8));
  dist1[0][0] = 0;
  q.push({0,0});
  while(!q.empty()){
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    if(row == n-1 &&col == m-1){
      break;  
    }
    for(int i = 0; i < 4; i++){
      int nrow = row +dir[i][0];
      int ncol = col +dir[i][1];
      if(!check(nrow, ncol, n, m))continue;
      if(dist1[nrow][ncol]  == 1e8 && grid[row][col] == '.'){
        dist1[nrow][ncol] = dist1[row][col] + 1;
        q.push({nrow, ncol});
      }
    } 
  }
  // robot 1 had travelled the shortest possible path followed by robot 2
  // if robot 1's path time is less than robot 2 by some margin, we can make robot 2 
  // walk the same path just 2 seconds later than robot 1 hence taking t+2 time;
  // if the path1 and path2's time taken is same we just simply have t as our answer
  if(dist[n-1][m-1] == dist1[n-1][m-1]){
    cout << dist[n-1][m-1];
    return;
  }
  cout << dist[n-1][m-1]+2;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
  freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}