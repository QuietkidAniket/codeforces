/**
 *    author: Anicetus_7
 *    created: 2025-09-13 17:56:45
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,q; cin>>n>>q;


  vector<string> a(n); 


  for(auto& x : a)cin>> x;

  int prefix[n][n+1] = {0};

  for(int i = 0; i< n; i++)
  {
    for(int j = 0; j< n; j++)
    {
      prefix[i][j+1] = prefix[i][j] + (a[i][j] == '*');
    } 
  }

  while(q--){
    int y1, x1, y2, x2; cin>> y1>>x1>>y2>>x2;
    int res =0;
    for(int i = y1-1; i< y2; i++){
      res += prefix[i][x2] - prefix[i][x1-1];
    }
    cout << res<< endl;
  }

  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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