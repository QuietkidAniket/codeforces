/**
 *    author: Anicetus_7
 *    created: 2025-06-25 00:57:08
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


#include <bits/stdc++.h>
using namespace std;

#define int long long

// Brute force: Try all possible partitions (Exponential in n)
int brute(int i, int parts, int m, vector<int>& a) {
    int n = a.size();
    if (parts > m) return LLONG_MAX;
    if (i == n) return (parts == m) ? 0 : LLONG_MAX;

    int res = LLONG_MAX;
    int curr_max = 0;

    for (int j = i; j < n; j++) {
        curr_max = max(curr_max, a[j]);
        int next = brute(j + 1, parts + 1, m, a);
        if (next != LLONG_MAX)
            res = min(res, curr_max + next);
    }

    return res;
}

// Optimized DP (O(n^2 * m))
int dp_solve(vector<int>& a, int m) {
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            int curr_max = 0;
            for (int j = i - 1; j >= 0; j--) {
                curr_max = max(curr_max, a[j]);
                if (dp[j][k - 1] != LLONG_MAX)
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + curr_max);
            }
        }
    }

    return dp[n][m];
}



void Solve(){
      int n = rng() % 10 + 1;        // n = 1 to 10
      int m = rng() % n + 1;         // m = 1 to n
      vector<int> a(n);
      for (int i = 0; i < n; i++)
          a[i] = rng() % 20;         // elements from 0 to 19

      int brute_ans = brute(0, 0, m, a);
      int dp_ans = dp_solve(a, m);

      if (brute_ans != dp_ans) {
          cout << "Mismatch found!\n";
          cout << "Test #" << T << "\n";
          cout << "Array: ";
          for (int x : a) cout << x << " ";
          cout << "\nSubarrays: " << m << "\n";
          cout << "Brute: " << brute_ans << "\n";
          cout << "DP:    " << dp_ans << "\n";
          break;
      }else cout << "All tests passed!\n";
    return 0;
  
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