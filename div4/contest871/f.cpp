/**
 *    author: Anicetus_7
 *    created: 2025-09-20 23:30:36
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n,m; cin>>n>>m;
  int indegree[n+1] = {0};
  for(int i= 0; i <m; i++){
    int u, v; cin>>u>>v;
    indegree[u]++;
    indegree[v]++;
  }   
  set<int> st;
  for(int i = 1; i <=n; i++){
    if(indegree[i] == 1)continue;
    st.insert(indegree[i]);
  }

  
  
  cout << x << " " <<  y-1<< endl;
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