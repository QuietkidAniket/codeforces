/**
 *    author: Anicetus_7
 *    created: 2025-09-20 10:11:24
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int t;
  int n; cin>> n; 
  cin>>t;
  vector<int> a(n);
  for(auto& x : a)cin>> x;

  vector<int> prefix(n+1,0);
  prefix[0] = 0;
  for(int i = 0; i< n; i++){ 
    prefix[i+1] = prefix[i] + a[i];
  }

  int ans = 0;
  for(int i = 0 ; i < n; i++){
    int pos  = upper_bound(prefix.begin(),prefix.end(), 2*prefix[i]+t)- prefix.begin();
    ans = max(ans, pos-i-1);
  }
  cout << ans << endl;
}
// int solution(vector<int> a, int t){
  //    int n = a.size();
  //    int prefix[n+1] ;
  //   for(int i = 0; i< n; i++){ 
    
  //   }
  //   int ans = 0;
//   int sum = 0;
//   return ans;
// }

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        // cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}