/**
 *    author: Anicetus_7
 *    created: 2026-01-09 09:58:11
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int m,n, k; cin>> m>>n>>k;

  if(n % k == 0){
    vector<int> a(k);
    iota(a.begin(), a.end(),1);
    vector<int> b(a.rbegin(), a.rend());
    
    if(k&1){
      swap(a[k/2], a[k/2 + 1]);
    }
    for(int i =0; i <m; i++){
      if(i % 2 == 0){
        for(int j =0; j<n/k; j++)for(auto& x : a)cout<< x << " ";
        cout << endl;
      }else{
        for(int j =0; j<n/k; j++)for(auto& x : b)cout<< x<<" ";
        cout << endl;
      }
    }
  }else{
    int cnt = 1;
    for(int i =0; i <m; i++){
      for(int j = 0; j<n; j++)
      {
        cout << cnt << " "; 
        cnt++;
        if(cnt >k)cnt =1;
      }
      cout << endl;
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
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
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