/**
 *    author: Anicetus_7
 *    created: 2025-06-20 15:08:19
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());



void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  for(auto& x :a)cin>> x;
  vector<int> b(n);
  vector<int> c(n+1); //  time at which the ith car exits the tunnel
  for(int i  = 0; i< n; i++){
    cin>> b[i];
    c[b[i]] = i;
  }
  int cnt = 0, mx = c[a[0]];
  for(int i = 1; i< n; i++)
  { 
    if(mx >= c[a[i]]){
      cnt++;
    }else{
      mx =max(mx, c[a[i]]);
    }
  }

  cout << cnt << endl;
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>>t;
  for(int i = 1; i <= t; i++) 
    {
        // cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}