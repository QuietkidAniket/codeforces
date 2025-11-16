/**
 *    author: Anicetus_7
 *    created: 2025-11-16 00:15:30
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,m; cin>>n>>m;
  int a[n], b[m];
  int sum = 0;
  map<int,int> mp;
  for(int i = 0;i < n; i++)cin>>a[i];
  for(int i = 0;i < m; i++){
    cin>>b[i];
  }
  for(int i =0 ;i < n; i++){
    mp[a[i]]++;
  }
  int ptr = 0;

  int fsum = 0, res =0 ,ans =0;
  for(auto it = mp.rbegin(); it != mp.rend(); it++){
    
    int f = it->second;
    res += f;
    fsum += res;
    if(fsum >sum){
      break;
    }else  ans = res;
  }
  cout << ans<< endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        cout << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}