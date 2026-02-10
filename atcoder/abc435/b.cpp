/**
 *    author: Anicetus_7
 *    created: 2025-12-06 17:43:53
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
  int a[n+1];
  for(int i =1 ; i<= n ;i++) cin>>a[i];

  int cnt = 0;
  for(int l = 1; l <= n; l++){
    int sum = 0;
    for(int r = l ; r <=n ;r++){
      sum += a[r];
      bool flag = false;
      for(int i =l; i <= r; i++){
        if(sum%a[i] == 0){
          flag = true;
          break;
        }
      }
      if(!flag)cnt++;
    }
  }
  cout << cnt << endl;
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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