/**
 *    author: Anicetus_7
 *    created: 2025-09-08 02:39:00
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> a;
vector<vector<int>> dp;

int find(int l,int r){
  if(l > r)return 0;
  if(l == r){
    return a[l];
  }
  if(dp[l][r] != -1)return dp[l][r];
  int left = a[l] - find(l+1, r);
  int right = a[r] - find(l, r-1);
  return dp[l][r] = max(left, right);
}

void Solve(){
  int n; cin>>n;
  a.resize(n);
  dp.resize(n, vector<int>(n,-1));
  for(auto& x : a)cin>> x;

  cout << find(0, n-1) << endl;
  
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