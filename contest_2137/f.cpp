/**
 *    author: Anicetus_7
 *    created: 2025-09-08 15:58:48
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

  vector<int> a(n);
  vector<int> b(n);


  vector<int> z(n);
  for(auto& x : a)cin>> x;
  for(auto& x : b)cin>> x;

  int pmax[n+1] = {0};
  int res[n+1] = {0};
  // vector<int> pmax(n+1,0);
  // vector<int> res(n+1,0);

  for(int i = 0; i <n; i++){
    pmax[i+1] = max(pmax[i], a[i]);
  }

  for(int i = 0; i< n; i++)
  {
    res[i+1] = res[i];
    if(a[i] == b[i]){
      res[i+1]++;
    }else if(a[i] < pmax[i+1] && b[i] <= pmax[i+1]){
      res[i+1]++;
    }
  }

  for(int i = 0; i<= n; i++)
  {
   cout << res[i] << " " ; 
  }

  int ans= 0;
  for(int l  =0 ; l < n; l++){
    int sum = 0;
    for(int r = l; r <n; r++){
      sum += res[r+1] - res[l];
    }
    ans += sum;
  }


  cout << ans << endl;
  
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