#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;
ll dfs(int node,const vector<vector<int>>& adjl, const string& color, vector<vector<int>>& dp){
  ll sum = 0ll;
  for(int adjnode : adjl[node]){
    sum += dfs(adjnode, adjl, color, dp);
    dp[node][1] += dp[adjnode][1];
    dp[node][0] += dp[adjnode][0];
  }
  if(color[node-1] == 'W')dp[node][0]++;
  else dp[node][1]++;
  
  if(dp[node][0] == dp[node][1])return sum+1;
  else return sum;
}

void Solve(){
  vector<vector<int>> dp;
  int n; cin>> n;
  // 0 -> White, 1 -> Black
  dp.resize(n +1 ,vector<int>(2,0));
  // we take input of n-1 nodes from 2 to n
  vector<vector<int>> adjl(n+1);
  for(int child = 2; child <=n; child++){ 
    int parent; cin>> parent;
    adjl[parent].push_back(child);
  }
  string color; cin>> color; // of size n
  cout << dfs(1, adjl, color, dp);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
  freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}