/**
 *    author: Anicetus_7
 *    created: 2026-01-07 00:16:54
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define l first
#define r second

void Solve(){
  int n; cin>>n;

  vector<pair<int,int>> a(n);


  map<int,int> mp;
  vector<int> vec;
  for(auto& [l,r] : a){
    cin>> l>>r; 
    vec.push_back(l);
    vec.push_back(r);
  }
  sort(vec.begin(), vec.end());
  for(int x: vec){
    if(!mp.count(x))mp[x] = mp.size()+1;
  }

  vector<int> diff((int)mp.size() + 5, 0);
  
  for(auto& [l,r] : a){
    diff[mp[l]] += 1;
    diff[mp[r]+1] -= 1;
  }
  int ans = 0;
  for(int i =1;i <diff.size(); i++){diff[i] += diff[i-1]; ans= max(ans, diff[i]);}
  
  cout << ans <<endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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