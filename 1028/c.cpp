#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

ll gcd(ll a, ll b) {
    while (b) tie(a, b) = make_pair(b, a % b);
    return a;
}

void Solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll res = arr[0];
    int mine = arr[0], mincnt = 1;
    for (int i = 1; i < n; i++) {
        res = gcd(res, arr[i]);
        if (arr[i] < mine) {
            mine = arr[i];
            mincnt = 1;
        } else if (arr[i] == mine) {
            mincnt++;
        }
    }

    if (res == mine) {
        cout << n - mincnt << endl;
        return;
    }

    // Divide all elements by overall GCD
    vector<ll> l(n);
    for (int i = 0; i < n; i++) {
        arr[i] /= res;
        l[i] = arr[i];
    }

    // DP section to find min ops to reduce all to 1
    map<ll, ll> gcd_map;
    for (ll i = 0; i < n; i++) {
        map<ll, ll> new_map;
        new_map[l[i]] = 1;

        for (auto it : gcd_map) {
            ll g1 = it.first;
            ll cnt = it.second;
            ll new_gcd = gcd(g1, l[i]);
            if (new_map.count(new_gcd))
                new_map[new_gcd] = min(new_map[new_gcd], cnt + 1);
            else
                new_map[new_gcd] = cnt + 1;
        }

        for (auto it : new_map) {
            ll g1 = it.first;
            ll cnt = it.second;
            if (gcd_map.count(g1))
                gcd_map[g1] = min(gcd_map[g1], cnt);
            else
                gcd_map[g1] = cnt;
        }
    }

    ll ans = 0;
    if (gcd_map.count(1)) {
        ans = gcd_map[1] - 1;
    } else {
        ans = n - 1;
    }

    // Total operations = reduction ops + copy to others
    ans += n - 1;
    cout << ans << endl;
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