/**
 *    author: Anicetus_7
 *    created: 2025-09-30 22:07:54
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n; 
  vector<int> a(n+2);
  if(n <2 ){
    cout << -1 <<endl;
    return;
  }
  a[0] = -INF;
  for(int i =1 ; i <=n; i++)cin>> a[i]; 
  a[n+1] = -INF;
  int ans = INF;
  for(int i =1; i <=n ; i++){
    if(a[i-1] < a[i] && a[i] > a[i+1]){
      ans = min(ans, a[i]);
    }
  }
  cout << (ans == INF ? -1 : ans) << endl;
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