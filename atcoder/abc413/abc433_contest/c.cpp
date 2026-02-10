/**
 *    author: Anicetus_7
 *    created: 2025-11-28 21:35:08
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define elem first
#define freq second

void Solve(){
  string s; cin>>s;
  vector<pair<char,int>> vec; // element, contiguous frequency
  int cur_freq =0;
  char  cur_elem=  '0'-1;
  for(int i = 0;i < s.size(); i++){
    if(cur_elem == s[i])cur_freq++;
    else{
      vec.push_back({cur_elem, cur_freq});
      cur_elem = s[i];
      cur_freq  = 1;
    }
  }
  if(cur_freq  >0){
    vec.push_back({cur_elem, cur_freq});
  }
  int cnt= 0;
  for(int i = 0;i  < vec.size()-1; i++){
    if(vec[i].elem +1 == vec[i+1].elem){
      int len = min(vec[i].freq, vec[i+1].freq);
      cnt+= len;
    }
  }
  cout << cnt << endl;
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