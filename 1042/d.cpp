/**
 *    author: Anicetus_7
 *    created: 2025-08-14 18:24:48
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define vec vector

void Solve(){
    int n; cin>> n;
    vec<vec<int>> adjl(n+1);
    vec<int> deg(n+1,0);
    
    
    for(int i =0 ; i <n-1; i++){
        int u, v; cin>>u>>v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    

    int onedeg = 0;
    for(int node = 1; node <= n; node++){
        if(deg[node] == 1){
            onedeg++;
        }
    }

    int mn = 1e9;
    for(int node = 1 ; node <=n; node++){
        int leaftoroot= 0;
        for(int adjnode: adjl[node]){
            if(deg[adjnode]==1)leaftoroot++;
        }
        mn = min(mn, onedeg- leaftoroot-  (deg[node]==1));
    }
    cout <<mn <<endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}