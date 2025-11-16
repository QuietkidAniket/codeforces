/**
 *    author: Anicetus_7
 *    created: 2025-10-12 21:32:22
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
  vector<int> a;
  while(n > 0){
    if(n&1)a.push_back(1);
    else a.push_back(0);
    n >>=1;
  }
  int l =0, r= a.size()-1;

  while(l <= r&& a[l] == 0)l++;

  while(l <= r){
    if(a[l] != a[r]){
      cout << "NO" << endl;
      return ;
    }
    if(l == r && a[l]==1){
      cout << "NO" << endl;
      return ;
    }
    l++, r--;
  }
  cout << "YES" << endl;
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