#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int MOD = 1e9 + 7;
int n;
vector<vector<int>> g;
vector<int> size_sub;
unordered_set<int> usedSums;

int countWays(int u, int parent, vector<int>& a) {
    int res = 0;

    for (int val = 1; val <= 2; ++val) {
        a[u] = val;
        int valid = 1;
        int sum = val;
        for (int v : g[u]) {
            if (v == parent) continue;
            int child_sum = countWays(v, u, a);
            if (child_sum == -1) {
                valid = 0;
                break;
            }
            sum += child_sum;
        }

        if (valid && !usedSums.count(sum)) {
            usedSums.insert(sum);
            if (u == 0) {
                res = (res + 1) % MOD;
            } else {
                return sum;
            }
            usedSums.erase(sum);
        }
    }

    return (u == 0 ? res : -1);
}


int dfs(int u, int parent, vector<int>& a) {
    // size of subtree
    size_sub[u] = 1;
    for (int v : g[u]) {
        if (v != parent) {
            size_sub[u] += dfs(v, u, a);
        }
    }
    return size_sub[u];
}


void Solve(){
  cin >> n;
    g.resize(n);
    size_sub.resize(n);
    vector<int> a(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1, a);  

    int ans = countWays(0, -1, a);
    cout << ans << '\n';
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