/**
 *    author: Anicetus_7
 *    created: 2025-09-08 02:16:23
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

bitset<100001> dp;

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  for(auto& x : a)cin>> x;
  dp.reset();
  sort(a.begin(), a.end());
  int sum = accumulate(a.begin(), a.end(), 0ll);

  dp[0] = 1;
  for(int coin : a){
    for(int t = sum; t >= coin; t--){
      if(dp[t-coin])dp[t] = 1;
    }
  }

  cout << dp.count() -1<< endl;
  for(int i = 1; i <=sum ;i++){
    if(dp[i])cout << i << " ";
  }
  cout << endl;
  
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