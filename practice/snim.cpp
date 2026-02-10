/**
 *    author: Anicetus_7
 *    created: 2025-12-29 11:34:27
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int m; cin>>m; 
  vector<int> s(m); // m possible removal amounts
  for(auto& x : s)cin>> x;

  int n; cin>>n;
  vector<vector<int>> h(n); // n groups of heaps/piles
  for(int i =0;i<  n; i++){
    int l; cin>>l; // number of heaps/piles
    h[i].resize(l);
    for(int j = 0; j < l; j++){
      cin>>h[i][j];
    }
  }

  // calculating the nim till 10000
  vector<int> nim(10001);
  nim[0]  =0;
  // calculates the mex in each pile according to the given removal amounts
  vector<int> vis(10001,-1);
  
  for(int i = 1; i < 10001; i++){
    // mark the reachable states
    for(int x : s){
      if(i-x >=0)vis[nim[i-x]]=i;
    }
    int mex = 0;
    while(vis[mex] == i)mex++;
    nim[i] = mex;
  }
  
  // take each group
  for(int i = 0 ; i <n;i++){
    // calculating the nim of the subgames
    // calculates the total xor sum of (the mex of each pile)
    int xor_sum = 0ll;
    for(int pile: h[i]){
      int res= nim[pile];
      // cout << res << " + ";
      xor_sum ^= nim[pile];
    }
    if(xor_sum)cout << "W";
    else cout << "L";
  }
  cout <<endl;
  
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