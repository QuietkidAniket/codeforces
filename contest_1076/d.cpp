/**
 *    author: Anicetus_7
 *    created: 2026-01-25 20:31:56
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
  vector<int> b(n);
  for(auto& x : a)cin>> x;
  for(auto& x : b)cin>> x;
  sort(a.begin(), a.end());

  vector<int> pref(n+1,0);
  for(int i =0 ;i < n; i++){
    pref[i+1] = pref[i]+  b[i];
  }

  int ans = 0;
  for(int i = 0;i < n; i++){
    int rem_swords = n-i;
    int x= a[i];
    int pos = upper_bound(pref.begin(), pref.end(), rem_swords) - pref.begin() -1;
    int res= x*pos; 
    ans = max(ans, res);
  }
  
  cout <<  ans << endl;
  
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