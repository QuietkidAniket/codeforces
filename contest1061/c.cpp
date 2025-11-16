/**
 *    author: Anicetus_7
 *    created: 2025-10-24 20:55:38
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n, k; cin>>n >> k;
  vector<vector<int>> divs(n+1);
  for(int i =2; i<= n; i++){
    for(int j = i;j <=n ; j+=i){
      divs[j].push_back(i);
    }
  }

  vector<int> a(n); for(auto& x : a)cin>> x;

  sort(a.begin(), a.end());
  vector<vector<int>> cnt(n+1);

  for(int i =0; i <n; i++){
    for(int x: divs[a[i]]){
      cnt[x].push_back(i);
    }
  }
  for(int num = n; num >= 2; num--){
    int pos = n;
    // position of numbers greater than 4*num-1
    if(4*num <= n){
      pos = upper_bound(a.begin(), a.end(), 4*num-1)- a.begin();
    }
    // all numbers less than 4*num but divisible by num
    auto& vec = cnt[num];
    int g = lower_bound(vec.begin(), vec.end(), pos)- vec.begin();

    if(pos - g <= k){
      cout << num << endl;
      return;
    }
  }
  cout << 1 << endl;
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