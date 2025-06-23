/**
 *    author: Anicetus_7
 *    created: 2025-06-20 12:40:08
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n; cin>> n;
  set<int> used;
  for(int x =2; x*x <= n; x++){
    if(n%x == 0){
      used.insert(x);
      n /= x;
      break;
    }
  }
  for(int x =2; x*x <= n; x++){
    if(n%x==0 && used.count(x)  == 0){
      used.insert(x);
      n /= x;
      break;
    }
  }
  if(used.size() < 2 || n == 1 || used.count(n)){
    cout << "NO"<< '\n';
  }else{
    cout << "YES" << '\n';
    for(auto& x : used){
      cout << x << " ";
    }
    cout << n << endl;
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
        //cout << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}