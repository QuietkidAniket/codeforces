/**
 *    author: Anicetus_7
 *    created: 2025-06-20 14:37:09
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin >> n;
  vector<int> a(n);
  int yaser = 0;
  for(auto& x : a)
  {
    cin>>x;
    yaser += x;
  }
  int abel = 0, sum =0;
  for(int i = 1; i< n; i++)
  {
    sum = max(sum+a[i], a[i]);
    abel = max(abel, sum);  
  }
  sum = 0;
  for(int i = 0; i< n-1; i++)
  {
    sum = max(sum+a[i], a[i]);
    abel = max(abel, sum);  
  }
  if(yaser > abel){
    cout <<"YES" <<'\n';
  }else cout <<"NO" <<'\n';
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}