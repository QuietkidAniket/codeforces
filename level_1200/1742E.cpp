/**
 *    author: Anicetus_7
 *    created: 2025-08-30 10:35:08
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n; cin>>n;
  int queries; cin>> queries;
  int a[n]; for(auto& x : a)cin>> x;
  int q[queries]; for(auto& x : q)cin>> x;

  int prefix[n+1] = {0ll};
  int prefixmax[n+1] = {0ll};

  
  for(int i = 0; i< n; i++)
  {
     prefix[i+1] = prefix[i] + a[i];
     prefixmax[i+1] = max(prefixmax[i], a[i]);
  }


  for(const auto& x : q)
  { 
    int idx = upper_bound(prefixmax, prefixmax+n+1, x)- prefixmax-1;
    cout << prefix[min(idx,n)] << " ";
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