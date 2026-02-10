/**
 *    author: Anicetus_7
 *    created: 2025-12-16 21:42:58
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
  int n;
  cin >> n;

  vector<pair<pair<int, int>, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  int mnl = INF, mxr = -INF, cnt = 0;
  vector<int> vec(n);
  int i = 0;
  for (auto &[segment, idx] : a) {
    auto [l, r] = segment;
    if (l > mxr && cnt <= 1) {
      cnt++;
    }
    vec[idx] = cnt;
    mnl = min(mnl, l);
    mxr = max(mxr, r);
  }
  if (cnt == 1) {
    cout << -1;
  } else
    for (auto &x : vec)
      cout << x << " ";
  cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    // cout << "Case #" << i << ": \n";
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
