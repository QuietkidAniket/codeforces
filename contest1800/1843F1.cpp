/**
 *    author: Anicetus_7
 *    created: 2025-09-24 14:36:13
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define yes cout<<"YES\n";
#define no cout<<"NO\n";

void Solve(){
  int n; cin>>n;

  int cur = 1;
  int u, v, k,x;

  vector<vector<int>> adjl(n+1);
  auto dfs = [&](){

  }


  while(n--){
    char choice; cin>>choice;
    if(choice == '+'){ 
      cin>>v>>x;


    }else{
      cin>>u>>v>>k;

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
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}