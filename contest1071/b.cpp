/**
 *    author: Anicetus_7
 *    created: 2025-12-23 20:23:15
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  for(auto& x : a)cin>> x;

  int sum = 0ll;
  for(int i = 0; i< n-1; i++){
    sum += abs(a[i+1] - a[i]);
  }
  int ans = sum;
  for(int i = 0; i <n; i++){
    int res = 0;
    if(i+1< n)res += abs(a[i+1] -a[i]);
    if(i > 0)res += abs(a[i] - a[i-1]);
    if(i > 0 && i +1 <n)res -= abs(a[i+1] - a[i-1]);
    // cout << sum - res <<endl;
    ans = min(ans, sum - res);
  }
  cout << ans << endl;
  
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