/**
 *    author:  Anicetus_7
 *    created: 2025-06-20 02:07:56
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>> n;
  vector<int> p(n);
  for(auto& x : p)cin>>x;
  bool increasing = (p[0] < p[1]);
  vector<int> ans;
  ans.push_back(p[0]);
  for(int i = 2; i < n; i++){
    if(p[i-1] < p[i]){
      if(increasing){
        continue;
      }
      else{
        increasing = true;
        ans.push_back(p[i-1]);
      }
    }else{
      if(!increasing)continue;
      else{
        increasing =false;
        ans.push_back(p[i-1]);
      }
    }
  }
  ans.push_back(p.back());
  cout << ans.size() <<endl;
  for(auto& x : ans)cout << x << " ";
  cout << '\n';
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