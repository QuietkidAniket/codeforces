/**
 *    author: Anicetus_7
 *    created: 2025-09-17 21:02:06
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n;cin>>n;
  vector<int> a(n);

  for(auto& x : a)cin>> x;
  int l =0, r =0;
  for(int i =0; i <n; i++){
    if(a[i] == n){
      l = i, r = i;
      break;
    }
  }
  int cnt =n-1;
  while(l >= 0 && r < n && cnt > 0){
    int left = -1, right = -1;
    if(l-1 >= 0){
      left = a[l-1];
    }
    if(r +1< n){
      right = a[r+1];
    }
    if(cnt == left){
      l--;
    }else if( cnt== right){
      r++;
    }else{
      cout << "NO\n";
      return;
    }
    cnt--;
  }
  cout << "YES\n";
  
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