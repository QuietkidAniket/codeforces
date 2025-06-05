#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const ll mod = 998244353;

vector<vector<int>> dp;

int find(int i, int prev, const string& s){
  if(i == s.size()) return 0;
  if(dp[i][prev] != -1) return dp[i][prev];

  int take = 0;
  if(prev == 2 || (s[i] - '0') != prev)take = 1 + find(i + 1, s[i] - '0', s);

  int not_take = find(i + 1, prev, s);
  return dp[i][prev] = max(take, not_take);
}

void Solve() {
    string s; cin >> s;
    int n = s.size();
    dp.assign(n, vector<int>(3, -1)); // prev: 0, 1, or 2 (2 = undefined)
    cout << n - find(0, 2, s) << " ";
    ll ans = 0;
    int prev = 0;
    for(int i= n-1; i >= 0; i--){
      if(dp[i][2] == prev){
        int count = 1;
        while(i >= 0 && dp[i][2] == prev){
          count++, i--;
        }
        if(i < 0)break;
        ans  = (ans*count)%mod;
        prev = dp[i][2];
      }else{
        prev = dp[i][2];
      }
    }
    cout << ans;
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