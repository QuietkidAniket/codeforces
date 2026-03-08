/**
 *    author: Anicetus_7
 *    created: 2026-01-09 11:48:59
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)LLONG_MAX
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int k; 
int n; 
vector<int> a;
int f(int ind, int bt, vector<vector<int>>& dp){
  if(ind == n){
    return 0;
  }
  if(dp[ind][bt] != -INF)return dp[ind][bt];
  // take good
  int res = (a[ind]>>bt); 
  int take = f(ind+1, bt,dp) +  res - k;
  // not bad
  int not_take = f(ind+1, min(bt+1, 63ll),dp) +  (res>>1);
  return dp[ind][bt] =  max(take, not_take);
}

void Solve(){
  cin>>n; cin>>k;
  a.assign(n, 0);
  for(auto& x : a)cin>> x;
  // sort(a.rbegin(), a.rend());
  vector<vector<int>> dp(n+1, vector<int>(64,-INF));

  int res =(int)f(0, 0, dp);
  cout <<res << endl;
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