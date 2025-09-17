/**
 *    author: Anicetus_7
 *    created: 2025-09-12 15:15:51
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
  int grid[n][n];
  for(int i = 0; i< n; i++)
  {
    for(int j = 0; j< n; j++)
    {
     cin>>grid[i][j] ;
    } 
  }
  vector<int> vis(2*n+1, 0);
  vector<int> s;
  for(int  i = n-1; i >=1; i--){
    vis[(int)grid[n-1][i]]= 1; 
    s.push_back(grid[n-1][i]);
  }
  
  for(int i = n-1; i >=0; i--){
    vis[(int)grid[i][0]]= 1; 
    s.push_back(grid[i][0]);
  }

  for(int i  =1; i <= 2*n; i++){
    if(vis[i] == 0){s.push_back(i); break;}
  }
  reverse(s.begin(), s.end());
  for(auto x : s){
    cout << x << " ";
  }
  cout << endl;
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