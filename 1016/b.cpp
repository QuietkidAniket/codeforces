#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  string s; cin>> s;
  int n = s.size();
  // check for the indices for the first non zero element from right
  int index = n-1;
  for(int i = n-1; i >=0; i--){
    if(s[i] == '0')continue;
    else{
      index = i;
      break;
    }
  }
  ll ans = n - 1 - index;
  // cout << "index" << index<<endl;
  // count all non zero elements before the indices from left
  for(int i = 0; i< index; i++)
  {
    if(s[i] == '0')continue;
    else ans++;
  }
  cout  << ans;
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