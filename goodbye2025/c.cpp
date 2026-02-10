/**
 *    author: Anicetus_7
 *    created: 2025-12-27 20:32:40
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
  for(auto& x: a)cin>> x;

  vector<int> suff(n+1, 0); 
  vector<int> pref(n+1, 0); 
  for(int i =n-1; i>=0; i--)suff[i] = suff[i+1]+a[i];
  for(int i = 0 ; i <n; i++)pref[i+1] = pref[i] +abs(a[i]);
  
  int ans = -suff[1];
  for(int i=1;i<n;i++) {
    int res = a[0]+(pref[i]-abs(a[0]))-suff[i+1];
    ans = max(ans, res);
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