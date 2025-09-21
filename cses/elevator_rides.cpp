/**
 *    author: Anicetus_7
 *    created: 2025-09-18 17:14:48
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
  int x; cin>>x;

  vector<int> weight(n);
  for(auto& c : weight)cin>> c;

  //dp[S] = stores {minimum no. of rides, minimum possible weight} for subset S
  vector<pair<int,int>> dp(1<<n); 
  // for 0 weight, we just provide one ride (base case)
  dp[0] = {1,0};

  // we iterate 0...01...10....11.....100....101....
  for(int s = 1 ; s < (1<<n); s++){
    // dummy value
    dp[s] = {n+1, 0};
    // we select all the people who are present in the subset
    // and choose the most optimal removal at this step
    for(int p = 0 ; p < n; p++){
      if(s & (1<<p)){
        auto option = dp[s^(1<<p)];
        if(option.second + weight[p] <= x){
          option.second += weight[p];
        }else{
          option.first++;
          option.second = weight[p];
        }
        dp[s] = min(dp[s], option);  
      }
    }
  }
  
  cout << dp[(1<<n) -1].first << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0)
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