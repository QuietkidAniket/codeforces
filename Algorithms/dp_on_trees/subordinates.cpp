#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = false;
static const int mod = 1e9 + 7;

vector<int> dp;
void find(int node, vector<vector<int>>& adjl){
  for(int adjnode : adjl[node]){
    find(adjnode, adjl);
    dp[node] += dp[adjnode] +1;
  }
}

void Solve(){
  int n; cin>> n;
  vector<vector<int>> adjl(n+1);
  dp.resize(n+1, 0);
  for(int i = 2; i<=n; i++)
  {
    int u; cin>> u;
    adjl[u].push_back(i);
  }

  find(1, adjl);
  for(int i =1; i<= n; i++){
    cout << dp[i] << " ";
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