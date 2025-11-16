/**
 *    author: Anicetus_7
 *    created: 2025-10-25 20:33:54
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){

    vector<int> prev(151, 0);
    for(int x : a[0]) dp[x]++;
    
    for(int i = 1; i < m; i++){
        vector<int> cur(151, 0);
        for(int g = 1; g <= 150; g++){
            if(prev[g] == 0) continue;
            for(auto x : a[i]){
                int res = __gcd(g, x);
                cur[res] = (cur[res] + prev[g]) % MOD;
            }
        }
        prev = cur;
    }
    cout << prev[1]%MOD;
    return 
    
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