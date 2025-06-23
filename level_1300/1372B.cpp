/**
 *    author:  Anicetus_7
 *    created: 2025-06-17 14:10:47
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>> n;

  // we need to find n = a + b, where lcm(a,b) is minimized
  // => a*(n-a) /gcd(a,n-a) is min 
  // answer: k , n-k where k is the largest (proper) factor of n

  int p =0;
  for(int r = 2; r<= 100000; r++){
    if(n%r == 0){
      p = r;
      break;
    }
  }
  int a,b;
  if(p == 0){
    a =1, b =n-1;
  }else{
    a = n/p;
    b = n - a;
  }
  cout << a << " " <<b <<endl;
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  int tt = clock();
  #endif
  
  int t = 1;
  cin>> t;
  while(t--){
  Solve();
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}