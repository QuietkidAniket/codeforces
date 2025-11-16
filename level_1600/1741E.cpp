/**
 *    author: Anicetus_7
 *    created: 2025-09-29 08:17:49
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
  vector<int> b(n);

  for(auto& x : b)cin>> x;
    /**
     * special kind of partition dp on spaces between elements
    */
  vector<bool> dp(n+1,false); // dp[i] = partition set at ith space between a[i-1] and a[i]
  dp[0] = true; // partition is always set at 0th space 

  for(int i =0; i <n ;i++){
    if(i-b[i] >=0)dp[i+1] = dp[i+1] | dp[i-b[i]];
    if(i+b[i]+1<=n)dp[i+b[i]+1] = dp[i+b[i]+1] | dp[i];
  }

  cout << (dp[n]> 0 ? "YES" : "NO" ) << endl; // if partition set at nth space
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