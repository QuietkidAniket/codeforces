/**
 *    author: Anicetus_7
 *    created: 2025-08-28 13:17:35
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(998244353)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
    int l,r;  cin>> l >> r;
    // cout<< l << " " << r<< endl;
    int mx = 0;

    while((l<<mx) <= r)mx++;

    int power = 1ll << (mx-1);

    int sum = (r/power)-l + 1;

    power >>=1;
    if(mx > 1){
      sum += (mx - 1ll) * max(0ll,(r/(power*3ll) - l + 1));
    }
    
    cout << mx << " " << sum%MOD << endl;
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}