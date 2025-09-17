/**
 *    author: Anicetus_7
 *    created: 2025-09-13 12:59:42
**/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define INF (long long)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
#define N (int)(100*100 + 101); 

unordered_set<int> vis;
unordered_map<int,vector<int>> adjl;


bool dfs(int node, int par){
  vis.insert(node);
  for(auto adjnode:  adjl[node]){
    if(adjnode == par)continue;
    if(vis.find(adjnode) != vis.end())return true;
    if(dfs(adjnode, node))return true;
  }
  return false;
}


bool cycle(int node){
  return dfs(node,-1);
}

void Solve(){
  int n; cin>>n;
  adjl.clear();
  vis.clear();


  for(int i =0 ; i <n; i++){
    int u1,u2, v1,v2;
    cin>>u1>>u2>>v1>>v2;
    int a= u1*100 + u2;
    int b = v1*100 + v2;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
  }

  int ans =0;
  for(const auto& [u, vec]: adjl){
    if(vis.find(u) != vis.end())continue;
    if(cycle(u)){
      ans++;
    }
  }
  cout <<ans ;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  return 0;
}