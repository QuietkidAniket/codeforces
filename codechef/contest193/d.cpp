/**
 *    author: Anicetus_7
 *    created: 2025-07-02 21:04:01
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n; cin>> n;
  vector<vector<int>> adjl(n);
  vector<int> indegree(n,0);
  for(int i = 0; i< n-1; i++)
  {
    int u, v; cin>> u >>v;
    u--, v--;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
    indegree[u]++;
    indegree[v]++;
  }
  int cnt =0;
  for(int i = 0; i <n; i++){
    if(indegree[i] == 1){
        cnt++;
    }
  }
  if(cnt < 3){
      cout << 2*n - 1 << endl;
  }else{
      cout << n+1 << endl;
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