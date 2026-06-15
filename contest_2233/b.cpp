/**
 *    author: Anicetus_7
 *    created: 2026-06-09 20:26:14
**/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <bits/debug.h>
#else
#define DEBUG(x) 42 
#endif
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(4*n);
  for(int i =0; i < 4*n; i++ ){
    a[i] = i%n +1;
  }

  reverse(a.begin()+ n, a.begin()+2*n);
  reverse(a.begin()+2*n, a.begin()+3*n);
  if(n&1){
    swap(a[n/2], a[n/2-1]);
    swap(a[3*n + n/2], a[3*n+n/2-1]);
  }
  for(const auto& x : a)
  {
    cout <<x << " ";
  }
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