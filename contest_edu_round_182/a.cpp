/**
 *    author: Anicetus_7
 *    created: 2025-09-15 20:04:13
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
  int sum = 0;
  for(auto& x : a){cin>> x;sum +=x;}

  int prefix[n+1]  = {0};
  for(int i =0 ; i <n; i++){
    prefix[i+1] = prefix[i]  +a[i] ;
  }

  for(int l = 0; l < n-2; l++){
    int p = prefix[l+1]%3;
    for(int r =l+1;r < n-1; r++){
      int s = (prefix[n]- prefix[r+1])%3;
      int t = (prefix[r+1] - prefix[l+1])%3;
      if( t== s && p == s){
        cout << l+1 <<" " << r+1 <<  endl; 
        return;
      }else if(t!= s && t != p && p != s){
       cout << l+1 <<" " << r+1 <<  endl; 
        return;
      }
    }
  }
  cout << 0<<" "<< 0 << endl;
  
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