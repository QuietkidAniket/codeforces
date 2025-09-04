/**
 *    author: Anicetus_7
 *    created: 2025-07-23 20:29:16
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,k; cin>>n>>k;
  int sum  = 0ll;
  vector<int> a(n); for(auto& x : a){cin>>x; sum+=x;}
  sort(a.begin(), a.end());
  int x = a[0], y = a[1];
  int curr = (x + y + 1) / 2; // ceil((x + y)/2)
  int cnt = 0;
  for(int i = 1ll; i <= k; ++i){
      sum += curr;
      cnt++;
      int temp = (x + curr + 1) / 2; // ceil((x + curr)/2)
      if(temp == curr){
        break;
      }
      curr= temp;
  }
  cout << sum + (k-cnt)*curr << endl;
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