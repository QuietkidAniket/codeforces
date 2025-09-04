/**
 *    author: Anicetus_7
 *    created: 2025-07-19 21:46:43
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n),b(n),c(n),d(n);
  for(int i = 0; i< n; i++)
  {
   cin>> a[i]>>b[i]>>c[i]>>d[i];
  }
  int remones = 0, remzeros = 0;
  for(int i = 0; i< n; i++)
  {
    if(b[i]- d[i] > 0){
      remones += b[i]-d[i]  + min(a[i], c[i]);
    }
    if(a[i]- c[i] > 0)remzeros += a[i]-c[i];
  }
  cout << remones+remzeros << endl;
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