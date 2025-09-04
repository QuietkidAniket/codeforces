/**
 *    author: Anicetus_7
 *    created: 2025-07-19 17:32:04
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  string s;cin>>s;
  int n = s.size();
  int a=-1,b=-1;
  for(int i = 0; i< n; i++)
  {
   if(s[i] == '#' && a == -1)a = i+1;
   else if(s[i] == '#' && a != -1 ){
     b = i +1;
     cout << a<<","<<b<<endl;
     a= -1, b = -1;
   }
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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