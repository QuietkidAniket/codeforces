#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;
static const int N = 3*1e5;
static bitset<N> mask;
static const int init = [](){
  mask.set();
  return 0;
}();
void Solve(){
  ll n;cin>> n;
  string s1, s2; cin>> s1>> s2;
  bitset<N> a(s1);
  bitset<N> b(s2);
  int ones = a.count(), zeros = n-ones;
  int cnt_ones = 0, cnt_zeros = 0;
  for(int i = 0; i < n; i++){
    if(a[i] == b[i]){
      if(a[i])cnt_ones++;
      else cnt_zeros++;
    }
    else{
      int n_ones = ones-cnt_ones;
      int n_zeros = zeros-cnt_zeros;
      if(n_ones != n_zeros){
        cout << "NO";
        return;
      }
      a = a ^ mask;
      if(a[i])cnt_ones++;
      else cnt_zeros++;
    }
  }
  cout << "YES";
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