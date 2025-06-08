#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
 ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll d = a[1] - a[0];
    for (ll i = 1; i < n; i++) {
        if ((a[i] - a[i - 1]) == d) continue;
        else {
            cout << "NO";
            return;
        }
    }

    ll sub = (d >= 0) ? 1 : n;
    ll x = a[0] - abs(d) * sub;

    if (x  >= 0 && x) {
        cout << "YES";
    } else {
        cout << "NO";
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