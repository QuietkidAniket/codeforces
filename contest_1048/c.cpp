/**
 *    author: Anicetus_7
 *    created: 2025-09-08 21:28:02
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


vector<int> find(int n, int k){
  int p = 1ll;
  while(p <= (1ll<<k)){
    if(n&p)break;
    p<<=1;
  }
  p <<=1;
  vector<int> res;

  while(p <= (1ll <<k)){
    if(n&p){
      res.push_back(2);
    }else{
      res.push_back(1);
    }
    p <<= 1;
  }
  return res;
}

void Solve(){
  int k, x;
  cin >> k >> x;

  int n = (1ll << k);

  if(n == x){
    cout << 0 << endl<<endl;
    return ;
  }

  vector<int> ans;
  if (n < x ){
    ans = find((1ll<<(k+1))-x,k);
    for(auto& x : ans){
      if(x == 1)x = 2;
      else x = 1;
    }
  }else{
    ans = find(x,k);
  }
  cout << ans.size() << endl;
  for (auto c : ans) {
    cout << c << " ";
  }
  cout << endl;

}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
      //cout << "Case #" << i << ": \n";
      Solve();
  }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}