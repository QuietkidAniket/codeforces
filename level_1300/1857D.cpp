#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n; cin>> n;
  vector<pair<int,int>> c(n);
  for(int i = 0; i < n; i++){
    c[i].second = i+1;
    cin>> c[i].first;
  }
  for(int i = 0; i< n; i++)
  {
    int x;
    cin>> x;
    c[i].first -= x;
  }
  sort(c.rbegin(), c.rend());

  int max_cv = c[0].first;
  int i = 0;
  vector<int> ans;
  while(i < n && c[i].first == max_cv){
    ans.push_back(c[i++].second);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for(const auto& x: ans)cout << x << " ";
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