/**
 *    author: Anicetus_7
 *    created: 2025-08-26 21:14:47
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n;  cin>> n;
  vector<int> a(n);
  for(auto& x : a)cin>> x;
  if(n < 3){
    cout << max(0ll,a[0] - a[1]) << endl;
    return;
  }
  int ans = 0;  
  for (int i = 1; i < n; i += 2) {
    if (i == n-1) {  
        if (a[i] < a[i-1]) {
            int t = a[i-1] - a[i];
            ans += t;
            a[i-1] -= t;
        }
    } else {  
        if (a[i] < a[i-1] + a[i+1]) {
            int t = (a[i-1] + a[i+1]) - a[i];
            ans += t;
            a[i+1] = max(0ll,a[i+1]-t);
        }
    }
}
  cout << ans<< endl;
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