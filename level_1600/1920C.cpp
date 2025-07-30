/**
 *    author: Anicetus_7
 *    created: 2025-06-30 20:25:32
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>> n;
  vector<int> arr(n); for(auto& x : arr)cin>> x;

  auto check = [&](int k){
      // check if corresponding subsequences' gcds are not equal to 1
      int res = abs(arr[k] - arr[0]);
      for(int i =0; i < n - k; i++){
        res = gcd(abs(arr[i + k] - arr[i]), res);
        if(res ==1){
          return false;
        }
      }
      return true;
  };

  int ans = 0;
  for(int k = 1; k <=n; k++){
    if(n%k)continue;
    ans += check(k);
  }
  cout << ans << '\n';
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
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