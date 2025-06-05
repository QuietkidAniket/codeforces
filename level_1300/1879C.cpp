#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 998244353;

ll fact(ll n){
  ll res = 1;;
  for(int i= n; i > 1;i--){
    res = (res%mod*i%mod);
  }
  return res;
}

void Solve(){
  string s; cin>> s;
  ll x, y;
  int i = 0, j = 0;
  int min_ops = 0;
  ll res = 1;
  int n = s.size();
  int alternating = 0;
  while(i < n){
    j = i+1;
    int cnt = 1;
    while(j < n && s[j] == s[i]){
      cnt++;
      j++;
    }
    alternating++;
    min_ops += cnt-1;
    res = res%mod * cnt%mod;
    i = j;
  }
  res *= fact(n - alternating);
  cout << n - alternating << " " << res%mod;
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