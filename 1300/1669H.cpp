#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  vector<int> cnt(1<<5, 0);
  int n; cin>> n;
  ll k; cin>> k;

  for(int i = 0; i < n; i++){
    int x; cin>>x;
    for(int j = 0; j <=30; j++){
      if(x & 1)cnt[j]++;
      x >>= 1;
    }
  }
  int mask = 0;
  int i = 30;
  while(k >= 0ll && i >= 0){
    if(n - cnt[i] <= k){
      k = k - (n -cnt[i]);
      mask |= (1<<i);
    }
    i--;
  }
  cout << mask;
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