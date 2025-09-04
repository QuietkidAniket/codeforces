/**
 *    author: Anicetus_7
 *    created: 2025-07-05 17:40:58
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  queue<pair<int,int>> q;
  for(int i= 0; i < n; i++){
    int query;cin>> query;
    if(query == 1){
      int c, x;cin>> c>>x;
      q.push({x,c});
    }else{
      int k; cin>>k;
      int sum = 0;
      while(k >0 && !q.empty()){
        auto [x, freq] = q.front();
        if(k >= freq){
          k -= freq;
          sum += freq*x;
          q.pop();
        }else{
          sum += k*x;
          q.front().second = freq-k;
          break;
        }
      }
      cout << sum << endl;
    }
  }
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
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