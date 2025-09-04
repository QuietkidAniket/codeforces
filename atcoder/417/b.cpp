/**
 *    author: Anicetus_7
 *    created: 2025-08-03 15:10:05
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define vec vector<int> 

void Solve(){
  int n,m; cin>>n>>m;
  vec a(n), b(m);
  for(auto& x : a)cin>>x;
  for(auto& x : b)cin>>x; 
  multiset<int> st(a.begin(), a.end());

  for(auto& x : b){
    if(st.find(x)!=st.end())st.erase(st.find(x));
  }

  for(auto x : st)cout << x << " ";
cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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