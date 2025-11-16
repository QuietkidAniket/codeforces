/**
 *    author: Anicetus_7
 *    created: 2025-09-30 09:24:30
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>> n;
  vector<int> x(n), t(n);
  for(auto& _ : x)cin>> _;
  for(auto& _ : t)cin>> _;

  // Median Trick
  // ans = minarg F(b) = ∑ (xi -ti - b)
  // let xi-ti be ci....  minimal ∑ |ci - b| is at b = median(c) 

  vector<int> c(n);
  int sum = 0;
  for(int i=0; i <n; i++){
    c[i] = x[i] - t[i];
    sum += c[i];
  }
  sort(c.begin(), c.end());

  // cout << c[(int)c.size()/2] << endl;
  cout << sum /(int)c.size() <<endl;

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