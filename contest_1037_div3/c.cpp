/**
 *    author: Anicetus_7
 *    created: 2025-07-17 20:28:27
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, k; cin>>n>>k;
  vector<int> h(n); for(auto& x: h)cin>>x;
  int start = h[k-1];
  sort(h.begin(), h.end());
  int ind = upper_bound(h.begin(), h.end(), start) - h.begin();
  ind--;
  int prev = start, level =0;
  for(int i = ind+1; i <n ; i++){
    if(h[i]-prev + level > prev){
      cout << "NO\n";
      return;
    }
    level += h[i]- prev;
    prev = h[i];
    if(h[i] == h.back())break;
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
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}