/**
 *    author: Anicetus_7
 *    created: 2025-09-17 11:43:44
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

  long long  res = n*(n+1)/2ll;
  if(res & 1){
    cout << 0 << endl;
    return;
  }
  res >>=1;
  vector<int> dp(res+1);
  dp[0] =1;
  for(int i =1 ; i <=n ;i++){
    for(int t = res; t>= i;t--){
      dp[t] = (dp[t]+dp[t-i])%MOD;
    }
  }

  cout << (dp[res] *500000004ll)%MOD << endl;
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