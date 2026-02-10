/**
 *    author: Anicetus_7
 *    created: 2025-12-20 10:30:51
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
  for(auto& x : a)cin>> x;


  int g = a[0];
  int ones = a[0] == 1;
  for(int i = 1;i < n; i++){g = gcd(g, a[i]);ones += a[i]==1;}

  if(g != 1){
    cout << "-1\n";
    return;
  }
  if(ones > 0){
    cout << n-ones << endl;
    return;
  }

  int mn = n;
  for(int i =0;i < n; i++){
    g = a[i];
    for(int j =i+1; j<n; j++){
      g = gcd(g, a[j]);
      if(g == 1){
        mn = min(mn, j-i);
        break;
      }
    }
  }
  cout << mn +n -1 << endl;

}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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