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

  int u, v, k,x;

  // maximum suffix  array sum -> either +ve or 0
  int suffixmx[n+2] = {0}; 
  // minimum suffix array sum -> either -ve or 0
  int suffixmn[n+2] = {0};

  // node 1 has value 1 (given)
  suffixmx[1] = 1; suffixmn[1] = 0;

  int ansmx[n+2] = {0}, ansmn[n+2]  = {0};
  ansmx[1] =1;
  ansmn[1] =0;

  int cur = 2;
  while(n--){
    char choice; cin>>choice;
    if(choice == '+'){ 
      cin>>v>>x;
      suffixmx[cur] = max(suffixmx[v] + x, 0ll);  
      suffixmn[cur] = min(suffixmn[v] + x, 0ll);
      ansmx[cur] = max(ansmx[v], suffixmx[cur]);
      ansmn[cur] = min(ansmn[v], suffixmn[cur]);
      cur++;
    }else{
      cin>>u>>v>>k;
      if(ansmn[v] <= k &&  k <= ansmx[v]){
        yes
      }else no
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
        // cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}