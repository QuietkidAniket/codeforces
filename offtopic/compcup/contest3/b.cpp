/**
 *    author: Anicetus_7
 *    created: 2025-10-16 21:05:39
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

  vector<string> a(n);
  for(auto& x : a)cin>> x;

  multiset<string> st;

  for(int i =0 ; i < n ; i++){
    st.insert(a[i]);
  }
  for(int i =0; i <n; i++){
    st.erase(st.find(a[i]));
    string s = a[i];
    reverse(s.begin(), s.end());
    string s2 = s.substr(0,s.size()-1);
    
    reverse(s2.begin(), s2.end());
    if(st.find(s) != st.end() || st.find(s2) != st.end()){
      cout << "Yes" << endl;
      return; 
    }
    st.insert(a[i]);
  }
  cout << "No" << endl;
  
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