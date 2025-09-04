/**
 *    author: Anicetus_7
 *    created: 2025-06-24 18:59:33
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


int a[40], b[40];

void Solve(){
  int n; cin>>n;
  for(int i = 0; i< n; i++)
  {
   cin>> a[i] ;
  }
  for(int i = 0; i< n; i++)
  {
   cin>> b[i] ;
  }
  // sort
  vector<pair<int,int>> ans;
  for(int i = 0; i <n-1; i++){
    for(int j = 0; j < n- 1 - i; j++){
      if(a[j] >= a[j+1]){
        swap(a[j], a[j+1]);
        ans.push_back({ 1, j+1});
      }
    }
  } 
  for(int i = 0; i <n-1; i++){
    for(int j = 0; j < n-1-i; j++){
      if(b[j] >= b[j+1]){
        swap(b[j], b[j+1]);
        ans.push_back({2, j+1});
      }
    }
  } 
  if(a[0] >= b[0]){
    ans.push_back({3, 1});
    swap(a[0], b[0]);
  }
  for(int i =1 ;i < n; i++){
    if(a[i] >= b[i]){
      if(b[i-1] < a[i]){
        ans.push_back({3, i+1});
        swap(a[i], b[i]);
      }else{
        ans.push_back({1, i});
        ans.push_back({3, i});
        ans.push_back({2, i});
        swap(a[i], b[i-1]);
      }
    }
  }
  cout << ans.size() << endl;
  for(auto& [x, y] : ans){
    cout << x << " " << y <<endl;
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
        cout << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}