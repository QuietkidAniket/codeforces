/**
 *    author: Anicetus_7
 *    created: 2025-12-18 15:03:54
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> gang(n+1,0);

  for(int i = 1; i <=n ; i++){
    cin>> gang[i];
  }

  vector<int> vis(n+1, 0);
  bool print = false;
  function<void(int)> dfs = [&](int node) -> void{  
    vis[node] = 1;
    for(int adjnode = 1; adjnode<= n; adjnode++){
      if(vis[adjnode] == 1 || gang[adjnode] == gang[node])continue;
      if(print)cout << node << " " << adjnode << endl;
      dfs(adjnode);
    }
  };

  int 

  dfs(1);
  int sum = accumulate(vis.begin()+1, vis.end(), 0ll);
  if(sum != n){
    cout<< "NO\n";
  }else{
    cout<< "YES\n";
    vis.assign(n+1, 0);
    print = true;
    dfs(1);
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
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}