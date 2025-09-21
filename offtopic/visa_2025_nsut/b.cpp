/**
 *    author: Anicetus_7
 *    created: 2025-09-20 10:46:10
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<vector<int>> grid(n, vector<int>(n));
  for(int i = 0; i< n; i++)
  {
   for(int j = 0; j< n; j++)
   {
    cin>>grid[i][j];
   } 
  }

  
  int ans1 =1e9;
  int ans2= 1e9;
  int t = (n-1)/2;
  for(int x= 0; x <= 2; x++){
    vector<vector<int>> vis(n, vector<int>(n,0));
    int cnt = 0;
    for(int i =0 ; i <= t; i++){ 
      if(n-i-1 != i){
        cnt += (grid[i][n-i-1] != x) + (grid[i][i] != x);
      }else cnt += (grid[i][i] != x);
      vis[i][i] = 1;
      vis[i][n-1-i] =1; 
    }
    for(int i =t+1; i < n; i++){ 
      cnt += (grid[i][t] != x);
      vis[i][t]= 1;
    }

    int c = 0;
    for(int i = 0; i <n; i++){
      for(int j = 0; j <n; j++){
        if(vis[i][j])continue;
        c += (grid[i][j] != x);
      }
    }
    ans1 = min(ans1, cnt);
    ans2 = min(ans2, c);
    // cout << ans1 << ", " << ans2 << endl;
  }

  cout <<ans1 + ans2 <<endl;

  
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