/**
 *    author: Anicetus_7
 *    created: 2026-01-20 02:51:36
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
  vector<int> d(n);
  vector<int> t(n);
  vector<int> cntd(n+1,0);
  vector<int> cntt(n+1,0);
  for(int i =0; i <n; i++){
    cin>>t[i] >>d[i];
    cntd[d[i]]++; cntt[t[i]]++;
  }
  int ans = n*(n-1)*(n-2)/6;
  for(int i = 0; i <n; i++){
    ans -= max(0ll, (cntt[t[i]]-1)*(cntd[d[i]]-1));
  }
  cout <<ans << endl;
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