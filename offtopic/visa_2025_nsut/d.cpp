/**
 *    author: Anicetus_7
 *    created: 2025-09-30 23:06:13
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  string s; cin>>s;
  string ans =s;
  int n = s.size();
  string pref;
  string suf(s.rbegin(), s.rend());
  for(int i =0 ;i  <n; i++){
    pref = pref + s[i];
    suf.pop_back();
    string a(pref.begin(), pref.end());
    string b(suf.begin(), suf.end());
    reverse(a.begin(), a.end());
    a = a + suf;
    b = pref + b;
    ans =min(ans, min(a,b));
  }
  cout << ans << endl;
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