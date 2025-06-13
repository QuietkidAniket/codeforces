#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef unsigned long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  ll n; cin>> n;
  vector<vector<ll>> monsters(n, vector<ll>(2));
  multiset<ll> stx,sty;
  for(ll i = 0; i< n; i++)
  {
    ll x, y;cin>> x>>y;
    monsters[i][0] =x, monsters[i][1] = y;
    stx.insert(x);
    sty.insert(y);
  }

  ll dx = *stx.rbegin() - *stx.begin();
    dx++;
    ll dy = *sty.rbegin() - *sty.begin();
    dy++;

  ll ans = dx*dy;
  if(n == 1){
    cout << 1;
    return;
  }
  for(ll i =0; i < n; i++){
    ll x  = monsters[i][0], y = monsters[i][1];
    stx.erase(stx.find(x)); // only delete one record having x-coord as x
    sty.erase(sty.find(y)); // only delete one record having y-coord as y
    ll dx = *stx.rbegin() - *stx.begin();
    dx++;
    ll dy = *sty.rbegin() - *sty.begin();
    dy++;

    ll area = dx*dy;

    if(area == n-1){
      area = min(area + dx, area + dy);
    }
    ans = min(ans, area);
    stx.insert(x);
    sty.insert(y);
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