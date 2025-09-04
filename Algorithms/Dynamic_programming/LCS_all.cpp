/**
 *    author: Anicetus_7
 *    created: 2025-08-27 17:26:55
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  string s1, s2;
  cin>>s1;
  cin>>s2;

  int m = s1.size();
  int n = s2.size();

  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

  for(int i = 1; i <=m; i++){
    for(int j = 1; j <=n; j++){
      if(s1[i-1] == s2[j-1])dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  cout << "Length of the longest subsequences: " << dp[m][n]<< endl;
  
  
  unordered_set<string> ans;
  
  function<void(int,int,string&)> dfs = [&](int i,int j, string& path) -> void{
    if(i ==0 || j == 0){
      if(path.size() == 0)return;
      reverse(path.begin(), path.end());
      ans.insert(path);
      reverse(path.begin(), path.end());
      return;
    }
    if(s1[i-1] == s2[j-1]){
      path.push_back(s1[i-1]);
      dfs(i-1, j-1, path);
      path.pop_back();
    }else{
      if(dp[i-1][j] > dp[i][j-1] ){
        dfs(i-1, j, path);
      }else if(dp[i-1][j] < dp[i][j-1]){
        dfs(i, j-1, path);
      }else{
        dfs(i-1, j, path);
        dfs(i, j-1, path);
      }
    }
    
  };
  
  string path = "";
  dfs(m, n, path);
  
  if(ans.size() == 0)return;

  cout << "\tsubsequences : " << endl;
  for(auto& x : ans){
    cout <<"\t"<< x << endl;
  }
  cout << endl;

}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}