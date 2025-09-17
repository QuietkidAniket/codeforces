/**
 *    author: Anicetus_7
 *    created: 2025-09-04 12:12:00
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, target; cin>>n>>target;
  vector<int> a(n);
  for(auto& x : a)cin>> x;


  vector<int> dp(target+1, INF);
  
  
  dp[0] =0;
  for(int t = 1; t <= target; t++){
    for(int coin : a){
      if(coin <= t)dp[t] = min(1+dp[t-coin], dp[t]);
    }
  }
  cout << (dp[target] == INF? -1 : dp[target]) << endl;

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