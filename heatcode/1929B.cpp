/**
 *    author: Anicetus_7
 *    created: 2026-01-09 11:08:34
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
  int k; cin>>k;
  int cnt =0;
  int i =1;
  // for(; i <= 2*(n-2) +2;i++){
  //   cnt += 2;
  //   if(cnt >= k){
  //     cout << i << endl;
  //     return;
  //   }
  // }
  if(2*(2*(n-2)+2) >= k){
    cout << (k+1)/2 << endl;
  }else{
    int i = 2*(n-2)+2;
    int cnt = 2*(2*(n-2)+2);
    // cout << cnt << " here " << i<< endl;
    while(cnt < k){
      cnt++;
      i++;
    }
    cout << i << endl;
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