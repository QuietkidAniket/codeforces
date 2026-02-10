/**
 *    author: Anicetus_7
 *    created: 2025-12-16 22:27:03
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

  vector<pair<int,int>> a(n);

  for(int i = 0; i< n; i++)
  {
    cin>>a[i].first; 
    cin>>a[i].second; 
  }

  sort(a.begin(), a.end());
  int rmx = -INF;
  for(auto& [l,r] : a){
    if(r >mxr)cnt++;
    rmx= max(mxr, r);
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