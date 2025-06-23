/**
 *    author:  Anicetus_7
 *    created: 2025-06-19 00:41:18
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
 int n; cin >> n;
  vector<vector<int>> arr(n, vector<int>(n, -1));

  auto check = [&](int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < n && arr[r][c] == -1;
  };

  int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
  int x = 0, y = 0, curr = 0;

  for (int i = n * n - 1; i >= 0; --i) {
    arr[x][y] = i;
    int nx = x + dir[curr][0], ny = y + dir[curr][1];

    if(!check(nx, ny)) {
      curr = (curr + 1) % 4;
      nx = x + dir[curr][0];
      ny = y + dir[curr][1];
    }

    x = nx;
    y = ny;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  
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