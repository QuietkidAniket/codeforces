/**
 *    author: Anicetus_7
 *    created: 2025-08-28 20:44:58
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    int n; cin >> n;
    int a[n], dp[n+1];

    vector<vector<int>> pos(n+1);

    int ind[n+1];

    for (int i = 0; i < n; i++){
        cin >> a[i];
        ind[i] = pos[a[i]].size();
        pos[a[i]].push_back(i);
    }
    dp[0] = 0;
    for(int i =1 ; i <=n; i++){
      dp[i] = dp[i-1];
      if(ind[i-1] -a[i-1] +1 >= 0)dp[i] = max(a[i-1]+ dp[pos[a[i-1]][ind[i-1]-a[i-1]+1] ] , dp[i]);
    }
    cout << dp[n] << endl;
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