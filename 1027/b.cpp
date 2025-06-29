#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  ll n, k; cin>>n >>k;
  string s; cin>> s;

  if(k > n/2){
    cout << "NO";
    return;
  }
  ll ones =0, zeros = 0;
  for(ll i = 0; i < n; i++){
    if(s[i] == '1')ones++;
    else zeros++;
  }
  ll max_good_pairs_ones = (ones/2);
  ll max_good_pairs_zeros = (zeros/2);
  ll mx = max_good_pairs_ones+ max_good_pairs_zeros;
  ll mn = n/2 - min(zeros, ones);
  if(mn <= k && k <= mx && (mx-k)%2 == 0){
    cout << "YES";
  }else cout << "NO";
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