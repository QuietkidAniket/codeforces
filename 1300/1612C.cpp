#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;


ll AP_SUM(ll k){
  return (k*k + k)>>1;
}

ll find_sum(ll line, ll k){
  if(line <= k)return AP_SUM(line);
  else return AP_SUM(k) + k*(line-k) -AP_SUM(line-k);
}

void Solve(){
  ll k,x; cin>> k>>x;
  ll low = 1, high = 2*k-1;
  ll ans = high;
  while(low <= high){
    ll mid = (low + high)>>1;
    if(find_sum(mid, k) >= x){
      ans = mid;
      high = mid -1;
    }else low = mid +1;
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