/**
 *    author: Anicetus_7
 *    created: 2025-12-23 22:22:11
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve1(){
  int n,m; cin>>n>>m;
  vector<vector<int>> adjl(n+1);
  for(int i =0 ;i < m;i++){
    int u, v; cin>>u>>v;
    adjl[u].push_back(v);
    adjl[v].push_back(u);
  }
  auto next = [](char col){
    if(col == 'r')return 'g';
    else if(col == 'g')return 'b';
    else return 'r';
  };
  vector<char> colour(n+1,'z');
  
  queue<pair<int,char>> q;
  q.push({1,'r'});
  colour[1] = 'r';
  while(!q.empty()){
    auto [node, col] = q.front();
    q.pop();
    colour[node]= col;
    for(int adjnode : adjl[node]){
      if(colour[adjnode] != 'z')continue;
      colour[adjnode] = next(col);
      q.push({adjnode, colour[adjnode]});
    }
  }

  for(int i = 1; i <= n ; i++)cout << colour[i] << "";
  cout <<endl;
}

void Solve2(){
  int q; cin>>q;
  for(int i = 0 ;i < q; i++){
    int d; cin>>d;
    string s; cin>>s;
    set<char> st(s.begin(), s.end());
    if(!st.count('r')){
      bool flag = false;
      for(int i =0 ; i< d; i++){
        if(s[i] == 'b'){
          cout << i+1 << endl;
          flag = true;
          break;
        }
      }
      if(!flag)cout << d <<endl;
    }else if(!st.count('g')){
      bool flag = false;
      for(int i =0 ; i< d; i++){
        if(s[i] == 'r'){
          cout << i+1 << endl;
          flag = true;
          break;
        }
      }
      if(!flag)cout << d <<endl;
    }else{
      bool flag = false;
      for(int i =0 ; i< d; i++){
        if(s[i] == 'g'){
          flag = true;
          cout << i+1 << endl;
          break;
        }
      }
      if(!flag)cout << d <<endl;
    }
  }
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin>>s;
  if(s == "first"){
    int t = 1;
    cin>> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": \n";
        Solve1();
    }
  }else{
    int t = 1;
    cin>> t;
    for(int i = 1; i <= t; i++) 
      {
          //cout << "Case #" << i << ": \n";
          Solve2();
      }
  } 
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}