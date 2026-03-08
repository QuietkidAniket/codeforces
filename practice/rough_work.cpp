/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    string s; cin>>s;
    int n= s.size();
    vector<vector<int>> dp(n+2, vector<int>(n+2,0));
    for(int i = 0 ; i < n;i++)dp[i][i] = 1;
    for(int i =n-1; i >=0; i--){
        for(int j = i+1; j < n; j++){
            dp[i][j] = dp[i+1][j] + 1; // in case a s[i]  is added after the [i, j] range
            for(int k = i+1; k <= j; k++){
                if(s[i] == s[k]){
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1] + dp[k+1][j]);
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
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
