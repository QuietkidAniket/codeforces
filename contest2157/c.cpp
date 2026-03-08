/**
 *    author: Anicetus_7
 *    created: 2025-12-31 10:33:14
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define left first
#define right second

void Solve()
{
  int n, k, q;
  cin >> n >> k >> q;
  vector<tuple<int, int, int>> queries(q);
  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;
    int l, r;
    cin >> l >> r;
    queries[i] = {l, r, x};
  }
  vector<int> ans(n + 2, 0);

  sort(queries.begin(), queries.end());

  vector<bool> vis(n + 2, false);
  int idx= 0;
  for (auto &[l, r, x] : queries)
  {
    if (x == 1)continue;
    int cnt = (ans[idx] + 1) % k;
    for (int i = max(l, idx+1); i <= r; i++)
    {
      ans[i] = cnt++;
      cnt %= k;
      vis[i] = true;
    }
    idx = max(idx, r);
  }
  for (auto &[l, r, x] : queries)
  {
    if (x == 2)continue;
    for (int i = l; i <= r; i++)
    {
      if (vis[i])ans[i] = k+1;
      else ans[i] = k;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main()
{
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    // cout << "Case #" << i << ": \n";
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}