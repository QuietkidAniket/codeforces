/**
 *    author: Anicetus_7
 *    created: 2026-01-08 12:42:04
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
  vector<pair<int,int>> a(n);
  set<int> st;
  for(auto& [l,r] : a){
    cin>>l>>r;
    st.insert(l);
    st.insert(r+1); // we just need to track the r+1th coordinate... as r is not involved in the difference array
  } 
  
  vector<int> actual;
  map<int,int> compress;
  int cnt=0;
  for(int x: st){
    compress[x] = cnt;
    actual.push_back(x);
    cnt++;
  }

  vector<int> diff(2*n+1);
  for(auto& [l,r] : a){
    diff[compress[l]]++;
    diff[compress[r+1]]--;
  }
  for(int i =1;i < 2*n; i++)diff[i] += diff[i-1];
  
  vector<int> cover(n+1);
  for(int i =1; i < actual.size(); i++){
    cover[diff[i-1]] += actual[i]- actual[i-1];
  }

  for(int k = 1;k <= n; k++){
    cout << cover[k] << " ";
  }
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
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}