/**
 *    author: Anicetus_7
 *    created: 2026-01-09 10:09:08
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  int ones = 0;
  for(auto& x : a){cin>> x; ones+= x==1;}
  
  vector<vector<int>> dp(n,vector<int> (n,0));
  for(int i =0; i< n; i++){ 
    int z = 0;
    for(int j = i; j < n ;j++){
      if(a[j] == 0)z++;
      dp[i][j] = z;
    }
  }
  int ans =0;
  for(int i =0 ; i < n; i++){
    for(int j = i; j <n; j++){  
      int res = ones - ((j-i+1)-dp[i][j]) + dp[i][j];
      ans = max(ans, res);
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