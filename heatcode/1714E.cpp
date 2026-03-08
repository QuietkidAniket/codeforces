/**
 *    author: Anicetus_7
 *    created: 2026-01-10 06:35:25
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  map<int,int> mp;
  for(auto& x : a){
    cin>> x;
    mp[x]++;
  }
  if(mp.size() == 1){
    cout << "YES\n";
    return;
  }
  // check for 5 and 0 in units digits
  if(mp.size() == 2 && mp.begin()->first%10==5 && mp.rbegin()->first == mp.begin()->first + 5){
    cout << "YES\n";
    return;
  }
  
  vector<vector<int>> freq(10, vector<int>(2,0)); //0 -> even, 1 -> odd
  
  for(int i =0 ;i < n; i++){
    int ud = a[i]%10;
    int rem = a[i]/10;
    int par = rem%2;
    freq[ud][par]++;
  }
  if(freq[0][0] || freq[5][0] || freq[0][1] || freq[5][1]){
    cout << "NO\n";
    return;  
  }
  // groups: (1,2,4,8) and (3,6,7,9)
  array<int,4> g1 = {1,2,4,8};
  array<int,4> g2 = {3,6,7,9};

  // if all zeros in one parity
  auto check = [&](array<int, 4>& g, int par){ 
    for(int i =0; i < 4; i++){
      if(freq[g[i]][par] != 0)return false;
    }
    return true;
  };
  bool A = !check(g1, 0);
  bool B = !check(g1, 1);
  bool C = !check(g2, 0);
  bool D = !check(g2, 1);
  bool res = (!C&& !B) || (!A && !D);
  if(res)cout << "YES\n";
  else cout << "NO\n";
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