/**
 *    author: Anicetus_7
 *    created: 2025-12-03 20:03:37
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,c; cin>>n>>c;
  int a[n];
  for(auto& x :a)cin>>x;
  string s;cin>>s;
  int sum1 = 0;
  for(int i = 0;i <n; i++){
    if(s[i] == '0'){
      sum1 += a[i];
    }
  }
  if(sum1 < c){
    cout <<  sum1  << endl;
    return;
  }
  int sum2=  0;
  for(int i = 0;i <n; i++){
    if(s[i] == '1'){
      sum2 += a[i];
    }
  }
  cout << max(sum1 + sum2 -c, sum1)<<endl;
  
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