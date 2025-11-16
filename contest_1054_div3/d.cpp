/**
 *    author: Anicetus_7
 *    created: 2025-09-30 00:15:36
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  string a; cin>>a;
  int ans = INF;

  for(char c = 'a'; c <='b'; c++){
    vector<int> pos;
    int cnt =0;
    for(int i =0 ; i <n; i++){  
      if(a[i] == c){cnt++; pos.push_back(i-cnt);};
    }
    
    // Median trick ...
    // if we need arg min F(b) = ∑ |a[i] - b + i| , i.e, b such that F(b) is minimised
    // then if c[i] = a[i] + i;
    // we need to minimize ∑ |c[i] - b| ... 
    // which is obviously minimum at b= median(c)
    sort(pos.begin(), pos.end());
    int res = 0;
    if (pos.size() > 0){
        int k = pos.size();
        int med = pos[k / 2];
        
        for (auto x : pos){
            res += abs(x - med);
        }
    }
    
    ans= min(ans, res);
  }
  cout << ans <<endl;
  
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