/**
 *    author: Anicetus_7
 *    created: 2026-01-11 15:31:32
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
  set<int> coprimes;
  coprimes.insert(1);
  int prod =1;
  for(int i  =2; i < n ;i++){
    if(__gcd(n, i) == 1){
      coprimes.insert(i);
      prod *= i;
      prod %= n;
    }
  }
  if(prod!= 1)coprimes.erase(prod);
  cout << coprimes.size() << endl;
  for(auto& x : coprimes)cout << x << " ";
  cout << endl;
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