#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n; cin>> n;
  vector<pair<ll,ll>> points(n);
  for(int i = 0; i< n; i++)cin >> points[i].first>> points[i].second;

  sort(points.begin(), points.end());
  ll ans = LLONG_MAX;
  // custom set which arranges points on basis of y coordinate
  auto cmp = [](pair<ll,ll> a, pair<ll,ll> b){
    if(a.second < b.second)return true;
    if(a.second == b.second)return a.first <= b.first;
    return false;
  };
  set<pair<ll,ll>, decltype(cmp)> st(cmp);
  int j = 0;
  for(int i =0; i < n; i++){
    ll d = ceil(sqrt(ans));
    while(j < i && points[i].first - points[j].first >= d) st.erase(points[j++]);

    auto low= st.lower_bound({points[i].first, points[i].second - d});
    auto high= st.upper_bound({points[i].first, points[i].second + d});
    for(auto it = low; it != high; it++){
      ll dx = points[i].first - it->first;
      ll dy = points[i].second - it->second;
      ans = min(ans,1ll*dx*dx + 1ll*dy*dy);
    }
    st.insert(points[i]);
  }

  cout <<"Smallest pair distance : " << sqrt(ans);
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