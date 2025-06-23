/**
 *    author:  Anicetus_7
 *    created: 2025-06-17 20:22:18
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  string s; cin>> s;
  vector<int> cnt(26,0);
  for(int i = 0; i < n-1; i++){
    cnt[s[i]-'a']++;
    if(cnt[s[i]-'a'] > 1){
      cout << "YES"<<endl;
      return;
    }
  }
  cnt.assign(26,0);
  for(int i = 1; i < n; i++){
    cnt[s[i]-'a']++;
    if(cnt[s[i]-'a'] > 1){
      cout << "YES"<<endl;
      return;
    }
  }
  if(s[0] == s.back())cnt[s[0]-'a']--;
  cout << "NO"<<endl;
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  int tt = clock();
  #endif
  
  int t = 1;
  cin>> t;
  while(t--){
  Solve();
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}