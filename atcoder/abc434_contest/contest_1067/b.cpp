/**
 *    author: Anicetus_7
 *    created: 2025-11-29 20:10:41
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
  int a[2*n];
  for(auto& x: a) cin>>x;

  int f[2*n+1];
  memset(f, 0, sizeof f);
  for(int x: a){
    f[x]++;
  }

  int o =0, e =0;
  for(int i = 1;i <= 2*n; i++){
    if(f[i] == 0)continue;
    if(f[i]&1){
      o++;
    }else e++;
  }

  if(o ==0 ){
    if(n%2 == e%2){
      cout << e*2;
    }else{
      cout << e*2-2;
    }
  }else{
    cout << o + e*2;
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