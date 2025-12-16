/**
 *    author: Anicetus_7
 *    created: 2025-12-12 18:34:20
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int m,n; cin>>n>>m;
  int a[m];
  for(int i =0 ;i < m ;i++){
    cin>>a[i];
  }
  sort(a, a+m);
  vector<int> b;
  for(int i =0 ;i < m-1; i++){
    b.push_back(a[i+1]-1 - a[i]);
  } 
  b.push_back(a[0]-1 +  (n-a[m-1]));
  
  sort(b.rbegin(), b.rend());
  int cnt = 0;
  for(int i =0;i < b.size(); i++){
    int num = b[i] -  4*i;
    if(num >= 1)cnt += max(1ll, num-1);
  }
  cout << n-cnt<< endl;
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