#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void dfs(int node, vector<vector<int>> adjl, vector<ll>& a, vector<ll>& dp, int par, ll sign){
  dp[node] = dp[par]  + sign*a[node];
  for(const auto& adjnode :  adjl[node]){
    if(adjnode != par){
      dfs(adjnode, adjl, a, dp, node, -1*sign);
    }
  }
}
void Solve(){
  int n; cin>> n;
  vector<ll> a(n+1);
  for(int i = 1; i <= n ; i++){
    cin>> a[i];
  }
  vector<vector<int>> adjl(n+1);
  for(int i = 0; i < n-1; i++){
    int u, v;
    cin>> u>> v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }
  vector<ll> dp;
  dp.assign(n+1,0ll); // stores alternating sum from node 1 till ith node
  for(int i = 
  dfs(1, adjl, a, dp, 0, 1ll);
  for(int i = 1; i <= n; i++){
    cout<< dp[i] << " ";
  }
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