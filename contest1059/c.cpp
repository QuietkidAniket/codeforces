/**
 *    author: Anicetus_7
 *    created: 2025-10-17 20:21:10
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int a, b; cin>>a>>b;
  
  auto find = [&](int n) -> int {
      if (n == 0) return 0LL;
      return 1LL << (63 - __builtin_clzll(n));
  };

  if(find(a) < find(b)){
    cout << "-1\n";
    return;
  }else if(a == b){
    cout << 0 << endl << endl;
    return;
  }
  vector<int> ans;
  int res = a^b;
  int p =1ll;
  while(res >0){
    if(res&1)ans.push_back(p);
    res >>=1;
    p <<=1;
  }
  cout << ans.size() <<endl;
  for(const auto& x : ans)
  { 
    cout << x << " ";
  }
  cout << endl;

}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}


