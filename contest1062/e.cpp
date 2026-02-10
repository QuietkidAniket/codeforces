/**
 *    author: Anicetus_7
 *    created: 2025-11-16 21:51:17
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
  int q; cin>>q;
  vector<int> a(n);

  for(auto& x : a)cin>> x;

  int msb =0;
  int mx = 0;
  for(int  i = 0 ;i <n ;i++){
    int t = a[i];
    int cnt= 0;
    while(t > 0){
      if(t&1)msb = max(msb, 1ll<<cnt);
      cnt++;
      t>>=1;
    }
    mx = max(mx, a[i]);
  }
  
  for(int i =0 ;i <q; i++){
    int t; cin>>t;
    int cnt= 0;
    int msb_ = 0;
    while(t > 0){
      if(t&1)msb_ = max(msb_, 1ll<<cnt);
      cnt++;
      t>>=1;
    }
    cout << min(msb_ - mx, msb_ - msb) << endl;
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