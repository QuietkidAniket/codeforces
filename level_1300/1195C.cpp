/**
 *    author: Anicetus_7
 *    created: 2025-08-06 17:09:49
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n; cin>>n;
    vector<int> a(n); for(auto& x :  a)cin>>x;
    vector<int> b(n); for(auto& x :  b)cin>>x;

    vector<vector<int>> dp(n+1, vector<int>(2,0)); //k -> 0 : from a taken last, 1 : from b taken last

    for(int i= 1; i <= n; i++){
            for(int k = 0; k <= 1; k++){
                if(k == 0){
                    int take = dp[i-1][1-k] + a[i-1];
                    int not_take = dp[i-1][k];
                    dp[i][k] = max(take, not_take);
                }else {
                    int take = dp[i-1][1-k] + b[i-1];
                    int not_take = dp[i-1][k];
                    dp[i][k] = max(take, not_take);
                }
            }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
//   cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}