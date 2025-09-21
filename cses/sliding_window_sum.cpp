/**
 *    author: Anicetus_7
 *    created: 2025-09-19 15:12:35
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, k;
  cin >> n >> k;
  int x, a, b, c;
  cin >> x >> a >> b >> c;
  vector<int> l(n);
  l[0] = x;
  for(int i=1;i<n;i++){
    l[i] = (a*l[i-1]+b)%c;
  }
  vector<int> ans;
  int sum=0;
  for(int i=0;i<k;i++){
    sum+=l[i];
  }
  ans.push_back(sum);
  for(int i=k;i<n;i++){
    sum = sum-l[i-k]+l[i];
    ans.push_back(sum);
  }
  int res = ans[0];
  for(int i=1;i<ans.size();i++){
    res = res^ans[i];
  }
  cout << res;
  
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