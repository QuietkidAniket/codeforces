#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;




void Solve(){
  int n ,m;
  cin>> n>>m;
  
  vector<ll> a(n);
  vector<ll> sum(n);
  for(int i= 0; i< n; i++)
  {
    for(int j = 0; j< m; j++)
    {
      ll temp;
      cin >> temp;
      sum[i] += temp;
      temp *= (m-j);
      a[i] += temp;
    }
  }

  sort(sum.begin(), sum.end());
  ll ans = 0ll;
  for(int i = n-1; i >= 0; i--){
    ans += a[i] + m*i*sum[i];
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