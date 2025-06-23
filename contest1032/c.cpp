/**
 *    author:  Anicetus_7
 *    created: 2025-06-17 20:43:27
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int m, n; cin>>m >>n;
  int maxelem = 0;
  vector<vector<int>> grid(m , vector<int>(n,0));
  for(int i = 0; i < m ;i++){
    for(int j = 0; j < n; j++){
      cin>> grid[i][j];
      maxelem = max(maxelem, grid[i][j]);
    }
  }
  int cnt=0;
  unordered_map<int,int> cntrow, cntcol;
  for(int i = 0; i < m ; i++){
    for(int j = 0; j < n; j++){
      if(grid[i][j] == maxelem){
        cntrow[i]++;
        cntcol[j]++;
        cnt++;
      }
    }
  }
  int rowid = -1, colid = -1;
  for(const auto& [row, fr] : cntrow){
    for(const auto& [col, fc] : cntcol){
      if(fr + fc - (grid[row][col] == maxelem) >= cnt){
        rowid = row, colid = col;
        break;
      }
    }
  }
  if(rowid == -1 && colid ==-1){
    cout << maxelem <<endl;
  }else
  {
    cout << maxelem -1<<endl;
  }
  
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  int tt = clock();
  #endif
  
  int t = 1;
  cin>> t;
  while(t--){
  Solve();
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}