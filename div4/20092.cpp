#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

int n, k;

pair<ll, ll> val(int i){
  ll val1 = i*(2*k + i - 1)/2;
  ll val2 = n*(2*k + n - 1)/2 - val1;
  return {val1, val2};
}

void Solve(){
  cin>> n>> k;
  int low = 1, high = n;
  int curr = 1;
  while(low <= high){
    int mid = (low+high)/2;
    auto res = val(mid);
    if(res.first  < res.second){
      curr = mid;
      low = mid +1;
    }else high = mid -1;
  }
  auto [a1, b1] = val(curr);
  auto [a2, b2] = val(curr+1);
  cout << min(b1 - a1, a2 - b2);
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