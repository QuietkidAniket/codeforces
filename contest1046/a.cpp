/**
 *    author: Anicetus_7
 *    created: 2025-08-28 20:05:20
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int a,b,c,d; cin>>a>>b>>c>>d;

  int x= c-a;
  int y = d -b;

  int mn =min(a,b);
  int mx =max(a,b);

  if(2*(1+mn) >= mx){
    mn = min(x,y);
    mx = max(x,y);
    if(2*(mn+1) >= mx){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }else cout << "NO\n";
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}