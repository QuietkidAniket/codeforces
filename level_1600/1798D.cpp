/**
 *    author: Anicetus_7
 *    created: 2025-07-30 19:16:23
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define vec vector<int>
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n); 
  for(auto& x : a)cin >> x;
  vec pos, neg;
  int zeros  = 0;
  for(auto& x : a)
  {
   if(x > 0)pos.push_back(x);
   else if(x < 0)neg.push_back(x);
   else{
    zeros++;
   }
  }

  if(zeros  == n){
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int sum = 0;
  int p = 0, ne = 0;
  for(int i =0 ; i < pos.size()+ neg.size(); i++){
    if(sum < 0){
      cout << pos[p] << ' ';
      sum += pos[p++];
    }else{
      cout << neg[ne] << ' ';
      sum += neg[ne++];
    }
  }
  while(zeros--)cout << "0 ";
  cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}