/**
 *    author: Anicetus_7
 *    created: 2025-08-29 21:14:03
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e9
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  for(int i = 0; i< n; i++)
  {
    cin >> a[i];
  }

  int mx =INF;
  int mn =0;
  for(int i = 0; i< n-1; i++){
    int x = a[i], y = a[i+1];
    if(x < y)mx= min((x+y)/2, mx);
    else if(x > y) mn = max((x+y+1)/2, mn);
  } 

  // for(auto& x : a)cout << x <<" ";
  if(mx >= mn)cout << mx << endl;
  else cout << -1 << endl;
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