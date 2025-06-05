#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n; cin>> n;
  int a[n];
  for(int i = 0; i< n; i++)
  {
    cin >> a[i];
  }
  unordered_map<int,int> mp;
  for(auto x : a)
  {
    for(int i = 2; i*i <= x; i++){
      int cnt = 0;
      if(x%i == 0)
      {
        while(x % i == 0){
          x /= i;
          cnt++;
        }
        mp[i] += cnt;
      }
    }
    if(x > 1)mp[x]++;
  }
  for(const auto& [x, freq] : mp){
    if(freq % n != 0){cout << "NO"; return;}
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