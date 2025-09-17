/**
 *    author: Anicetus_7
 *    created: 2025-09-16 19:13:01
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,a,b; cin>>n>>a>>b;
  vector<int> arr(n);
  for(auto& x : arr)cin>> x;

  int l =0, r =0;
  int sum = 0, mxsum = -INF;
  while(r < a){
    sum += arr[r];
    r++;
  }
  mxsum = max(mxsum , sum);

  while(r < n){
    sum += arr[r];
    while(r-l+1 >b){
      sum -= arr[l];
      l++;
    }
    mxsum = max(mxsum, sum);
    while( r-l >=a){
      sum -= arr[l];
      mxsum = max(mxsum, sum);
      l++;
    }
    r++;
  }
  cout << mxsum  <<endl;
  
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