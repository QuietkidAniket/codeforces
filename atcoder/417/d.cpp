/**
 *    author: Anicetus_7
 *    created: 2025-08-03 15:35:47
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// #undef int
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// template<typename Key, typename Value>
// using unordered_map = gp_hash_table<Key, Value>;
// #define int long long

void Solve(){
  int n; cin>>n;
  vector<array<int,3>> a(n);for(auto& x : a)cin>>x[0] >> x[1] >> x[2];
  int q; cin>>q;

  vector<int> b(q); for(auto& x : b)cin>>x;

  const int z = 1005;
  vector<vector<int>> dp(n+1,z);

  for(int i = n-1; i >= 0; i--){
    auto [p,l,r] = a[i];
    for(int j = 0; j <= z; j++){
      if(j <= p){
        dp[i][j] = dp[i+1][j+l];
      }else{
        dp[i][j] = dp[i+1][min(0ll,j - r)];
      }
    }
  }

  vector<int> sumb(n+1,0);  
  for(int i = 0; i<= n; i++)
  {
   sumb[i+1] = sumb[i] + a[i][2];
  }
  for(const auto& x : b){
    int ind = upper_bound(sumb.begin()+1, sumb.end(), x-z) - (sumb.begin()+1);
    x -= sumb[v];
    int ans = x;
    if(v < n){
      if(ans > z){
        ans -= a[ind][2];
        ind++;
      } 
      ans = dp[v][ans];
    }
    cout << ans << "\n";
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}