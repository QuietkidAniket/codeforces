/**
 *    author: Anicetus_7
 *    created: 2025-10-15 20:23:59
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n; 
  vector<int> x(n); for(auto& _ : x)cin>> _;
  vector<int> t(n); for(auto& _ : t)cin>> _;


  auto check = [&](ld mxt){
    ld l[n], r[n];
    ld l_ = -2e8;
    ld r_ = 2e8;
    
    for(int i = 0 ; i <n ; i++){
      if(t[i] > mxt){
        return false;
      }else{
        l[i] = x[i] - (mxt-t[i]);
        r[i] = x[i] + (mxt-t[i]);
        l_ = max(l_, l[i]);
        r_ = min(r_, r[i]);
      }
    }
    return l_ <= r_;
  };
  
  ld low = 0, high = 2e8;
  
  while(high - low > 1e-8){
    ld mid = (high+low)/2.0;
    if(check(mid)){
      high = mid;
    }else{
      low = mid;
    }
  }
  cout << fixed << setprecision(10);
  
  ld mxt = low;
  ld l[n], r[n];
  ld l_ = -2e8;
  ld r_ = 2e8;
  
  for(int i = 0 ; i <n ; i++){
      l[i] = x[i] - (mxt-t[i]);
      r[i] = x[i] + (mxt-t[i]);
      l_ = max(l_, l[i]);
      r_ = min(r_, r[i]);
  }
  cout << l_ << endl;
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