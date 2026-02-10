/**
 *    author: Anicetus_7
 *    created: 2025-12-17 15:55:34
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int a[3];
  for(auto& x :a)cin>>x;
  int n1, n; cin>>n;
  n1 = n;
  int x = gcd(n,a[0]);
  n /= x;
  int y = gcd(n,a[1]);
  n /= y;
  int z = gcd(n,a[2]);
  if(x*y*z != n1){
    cout << -1 <<endl;
  }else{
    cout << x -1 <<" " << y -1 <<" "<< z  -1<< endl;
  }
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