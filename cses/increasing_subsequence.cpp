/**
 *    author: Anicetus_7
 *    created: 2025-09-17 12:05:36
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
/** @brief Patience Sorting by C.L. Mallows (1973) and Michael Fredman (1975) */
void Solve(){
  int n; cin>>n;
  vector<int> a(n);

  for(auto& x : a)cin>> x;

  vector<int> lis;

  for(int x :  a){
    auto it = lower_bound(lis.begin(), lis.end(), x);
    if(it == lis.end())lis.push_back(x);
    else *it = x;
  }
  cout << lis.size() << endl;
}
 
/** @brief Standard O(n^2) approach using Tabulation (Bottom up ) Dynamic Programming */
void DP(){
  int n; cin>>n;
  vector<int> a(n);
  
  for(auto& x : a)cin>> x;
 
  int dp[n+1] = {0};  
  for(int i =1 ;i  <= n; i++){ 
    dp[i] = max(dp[i], 1ll);
    for(int j =i+1; j <=n; j++){
 
      if(a[i-1] < a[j-1]){  
        dp[j] = max(dp[j], 1 + dp[i]);
      }
    }
  }
  cout << *max_element(dp, dp + n+1) << endl;
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
