/**
 *    author: Anicetus_7
 *    created: 2025-07-22 20:24:01
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int a,b,k; cin>>a>>b>>k;
  if(k >=a && k >= b)cout << 1 <<endl;
  else if(a == b && a % k ==0){
    cout << 1 << endl;
  }else{ 
    int g =gcd(a,b);
    int ans = max(a/g, b/g);
    if(ans > k)cout << 2 << endl;
    else cout << 1 << endl;
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
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}