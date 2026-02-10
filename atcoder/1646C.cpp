/**
 *    author: Anicetus_7
 *    created: 2025-12-15 19:04:18
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(1e12+1)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> f;
vector<pair<int,int>> subsetsums;
void generate(){
  for(int prod = 1, i =2; prod < MAX ; prod *= i, i++)if((prod&(prod-1)) != 0)f.push_back(prod);
  int n = f.size();
  for(int s = 0; s < (1ll<<n); s++){
    int sum  =0;
    for(int i = 0;i <n; i++){
      if(s&(1ll<<i)){
        sum += f[i];
      }
    }
    subsetsums.push_back({sum, __builtin_popcountll(s)});
  }
}

void Solve(){
  int n; cin>>n;
  int ans= INF;
  for(auto& [s, bits] : subsetsums){
    int res = __builtin_popcountll(n-s) + bits;
    ans = min(ans, res);
  }
  cout << ans<< endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  generate();
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