/**
 *    author: Anicetus_7
 *    created: 2025-11-29 17:53:29
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n;
  int m; 
  cin>>n>>m;

  int freq[m+1];
  int sum[m+1];
  memset(sum, 0, sizeof sum);
  memset(freq, 0, sizeof freq);
  for(int i =0 ;i < n; i++){
    int ai, bi;cin>> ai>>bi;
    freq[ai]++;
    sum[ai] += bi;
  }
  for(int k = 1; k<= m; k++){
    double res = (double)sum[k] / freq[k];
    cout << fixed << setprecision(10)<< res <<endl;
  }
  
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