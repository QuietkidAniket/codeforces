/**
 *    author: Anicetus_7
 *    created: 2025-06-20 18:50:05
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const string s2 = "vvovv";
string s1;
vector<vector<int>> dp(1e6+1, vector<int>(5, -1));
int find(int i , int j){
  if(j < 0 )return 1;
  if(i < 0)return 0;
  
  if(dp[i][j] != -1)return dp[i][j];
  
  if(s1[i] == s2[j]){
    if(j==1 || j == 4){
      if( i> 0 && s1[i-1] == 'v' && s1[i-1] == s2[j-1]){
        dp[i][j]= find(i-2, j-2) + find(i-1, j);
      }else{
        dp[i][j] =  find(i-1, j);
      }
    }else{
      dp[i][j] = find(i-1, j)+  find(i-1, j-1);
    }
  }else{
    dp[i][j] = find(i-1, j) ;
  }
  return dp[i][j];
}

void Solve(){
  cin>>s1;
  dp.assign(s1.size(), vector<int>(s2.size(),-1));
  cout << find(s1.size()-1, s2.size()-1) << endl;
  // cout << dp[s1.size()-1][s2.size()-1] << endl;
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