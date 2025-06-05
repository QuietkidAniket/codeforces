#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n;
  cin >> n;
  ll arr[n];
  vector<pair<ll,ll>> pairs(n); // number, index
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
    pairs[i] = {arr[i], i+1};
  }
  sort(pairs.begin(), pairs.end());

  int i = -1;
  int res = 0;
  while(++i < n && pairs[i].first <= n){
    for(int j = i +1; j <n; j++){
      if(pairs[i].first * pairs[j].first > 2*n)break;
      res += ((pairs[i].first * pairs[j].first) == (pairs[i].second + pairs[j].second));
    }
  }
  cout << res;
  
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