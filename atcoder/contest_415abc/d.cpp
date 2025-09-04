/**
 *    author: Anicetus_7
 *    created: 2025-07-19 18:25:36
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());



void Solve(){
  int n, m; cin>> n>>m;
  vector<pair<int,int>> v(m);
  for(int i = 0; i< m; i++)
  {
    int a,b; cin>> a>>b;
    for(int i =0; i <n; i++){
      
    }
  }
  sort(a.begin(), a.end());
  priority_queue<pair<int,int>> pq;
  pq.push({n, 0ll});
  int ans = 0ll;
  while(!pq.empty()){
    auto [k, cnt] = pq.top();
    ans = max(ans, cnt);
    if(k <= 0){
      cout << ans << endl;
      return;
    }
    pq.pop();
    for(int i =0 ; i <m; i++){
      if(k < a[i].first){
        break;
      }else pq.push({k-a[i].first+a[i].second,cnt+1 });
    }
  }
  cout << ans << endl;
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}