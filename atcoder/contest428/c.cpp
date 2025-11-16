/**
 *    author: Anicetus_7
 *    created: 2025-10-18 18:11:33
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#undef int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Value>
using umap = gp_hash_table<Key, Value>;
#define int long long

void Solve() {
  int n;
  cin >> n;

  vector<pair<int,int>> stk; // {cur balance, min balance till now}
  stk.push_back({0, 0});

  while (n-- > 0) {
    int type; 
    cin >> type;

    if (type == 1) {
      char c; 
      cin >> c;
      auto [cur, mn] = stk.back();

      if (c == '(') cur++;
      else cur--;

      mn = min(mn, cur);
      stk.push_back({cur, mn});
    } 
    else {
      stk.pop_back();
    }

    auto [cur, mn] = stk.back();
    cout << ((cur == 0 && mn >= 0) ? "Yes\n" : "No\n");
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}