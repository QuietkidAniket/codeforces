/**
 *    author: Anicetus_7
 *    created: 2026-06-09 21:43:36
**/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#else
#define DEBUG(x) 42 
#endif
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n+2,0); 
  
  for(int i =1;i <=n; i++){
    cin>>a[i];
  }
  
  for(int i =1;i <=n; i++){
    if(a[i] != a[i-1])st.insert(a[i], a[i-1]), st.insert(s[i-1], s[i]);

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
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}