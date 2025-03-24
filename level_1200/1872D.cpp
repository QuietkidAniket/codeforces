#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

ll lcm(ll x, ll y){
  return (x*y)/gcd(x,y);
}

void Solve(){
  ll n,x,y;
  cin>> n>> x>>y;
  ll n_xy = n / lcm(x, y);
  ll n_x = n / x - n_xy;
  ll n_y = n / y - n_xy;
  ll tot_sum = (n*(n+1))/2;
  ll y_sum = (n_y*(n_y+1))/2;
  ll x_sum = tot_sum - ((n-n_x)*(n-n_x+1))/2;
  // cout << "sum_x : "<<x_sum << endl;
  cout << x_sum - y_sum;
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