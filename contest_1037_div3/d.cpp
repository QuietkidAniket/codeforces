/**
 *    author: Anicetus_7
 *    created: 2025-07-17 22:04:13
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct c{
  int l,r, real;
};

void Solve(){
int n,k; cin>>n>>k;
  vector<c> casino(n);
  for(int i = 0; i< n; i++)
  {
   int l,r, real; cin>>l>>r>>real;
   casino[i] = {l,r,real};
  }
  sort(casino.begin(), casino.end(), [](c& a, c& b){
    return a.l < b.l;
  });
  int prev = k;
  for(int i =0 ; i<n; i++){
    if(prev >= casino[i].l && prev <= casino[i].r){
      prev = max(casino[i].real, prev);
    }
  }
  cout << prev << endl;
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