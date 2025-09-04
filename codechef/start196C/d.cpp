/**
 *    author: Anicetus_7
 *    created: 2025-07-23 21:05:46
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  string s; cin>>s;
  
  if(n <= 2)cout << n << endl;
  else{
    // search for substring "1010" or "0101"
    string x = "01";
    string y = "10";
    int ans = 0;
    while(x.size() <= n){
        if(s.find(x) != string::npos || s.find(y) != string::npos){
            ans= max(ans, (int)x.size());
        } 
        x += "01";
        y += "10";
    }
    cout <<max(ans, 3ll)<<endl;
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
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}