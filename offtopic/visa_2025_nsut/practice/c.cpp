/**
 *    author: Anicetus_7
 *    created: 2025-09-30 18:42:12
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int m,n; cin>> m>>n;
  int sr; cin>>sr;
  vector<vector<int>> a(m, vector<int>(n));
  vector<vector<int>> pref(m, vector<int>(n+1,0));

  for(int i =0 ; i<m ;i++){
    for(int j = 0; j <n; j++){
      cin>>a[i][j];
      pref[i][j+1] = pref[i][j] + a[i][j];
    }
  }
  vector<vector<int>> ans(m, vector<int>(n,0)); 
  for(int i =0 ; i<m ;i++){
    for(int j = 0; j <n; j++){
      int ub = min(m-1, i+sr);
      int lb = max(0ll, i-sr);  
      int l = max(0ll, j-sr);
      int r = min(n-1, j+sr);
      double sum = 0;
      for(int k = lb; k <= ub; k++){
        sum += pref[k][r+1]- pref[k][l];
      }
      sum -= a[i][j];
      double total = (ub- lb+1)*(r-l+1)-1;
      if(total <= 0){ans[i][j] = (int)a[i][j]/2;}
      else ans[i][j] = (int)((sum/total) + (double)a[i][j])/2;
    }
  }
  for(int i =0 ; i<m ;i++){
    for(int j = 0; j <n; j++){
      cout << ans[i][j] << " ";
    }
    cout <<endl;
  }  
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