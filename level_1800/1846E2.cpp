#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

static const ll MAX = 1e18;

static ll dp[MAX+1];

static const int init = [](){
  for(int k = 3; k < 1000; k++){
    ll sum = 0;
    ll prod = 1;
    for(int x = 1; x <= 38; x++){
      sum += prod;
      if(sum >= MAX)break;
      if(x >=3)dp[sum] = 1;
      prod *= k;
    }
  }
  return 0;
}();


void Solve(){
  ll n; cin>> n;
  if(dp[n] ==1)cout << "YES";
  else cout << "NO";
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