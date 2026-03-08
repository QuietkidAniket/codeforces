/**
 *    author: Anicetus_7
 *    created: 2026-01-12 20:49:53
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int k;
map<int,int> dp;
int find(int n){
  if(n == k)return 0;
  if(n <k)return INF;
  if(dp.count(n))return dp[n];
  int res= find(n/2) + 1;
  if(n&1)res = min(res, find(n/2 + 1)+ 1);
  return dp[n] = res;
}

void Solve(){
  dp.clear();
  int n; cin>>n>>k;
  int ans = find(n);
  cout << (ans>=INF? -1 : ans) <<endl;
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