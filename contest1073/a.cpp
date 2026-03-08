/**
 *    author: Anicetus_7
 *    created: 2026-01-17 20:05:49
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
  vector<int> col(n);
  vector<pair<int,int>> a(n);
  for(int i =0 ;i< n ;i++){
    int x; cin>>x;
    a[i] = {x, i};
  }

  sort(a.begin(), a.end());

  for(int i =1;i< n ; i++){
    if(a[i].second%2 == a[i-1].second%2){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";

  
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