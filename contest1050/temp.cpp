/**
 *    author: Anicetus_7
 *    created: 2025-10-22 22:32:26
**/
#include <bits/stdc++.h>
using namespace std;

// the input is so horrendous as per problem statement
// so I have assumed we are provided with the adjacency list and variable n
void Solve(vector<vector<int>> adjl, int n){
  vector<int> color(n+1,-1);
  function<bool(int,int)> dfs  = [&](int node, int col)->bool{
    color[node] = col;
    for(int adjnode : adjl[node]){
      if(color[adjnode] != -1){
        if(color[adjnode] == col)return false;
        else continue;
      }
      if(!dfs(adjnode, 1-col))return false;
    }
    return true;
  };
  for(int node =1; node <= n; node++){
    if(color[node] == -1){
      if(!dfs(node, 0)){
        cout << "false\n";
        return;
      }
    }
  }
  cout << "true\n";
}