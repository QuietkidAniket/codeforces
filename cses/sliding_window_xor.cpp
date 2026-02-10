/**
 *    author: Anicetus_7
 *    created: 2026-01-16 23:10:21
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, k; cin>>n>>k;
  int x, a, b, c; cin>>x>>a>>b>>c;

  vector<int> p(35, 0);  
  deque<int> dq;
  int cur = x;
  int sum = 0;
  for(int i = 1;i <= k; i++){
    dq.push_back(cur);
    sum ^= cur;
    cur = (cur*a + b)%c;
  }
  int ans = sum;

  for(int i = k+1;i <= n; i++){
    sum ^= cur;
    dq.push_back(cur);
    int removed = dq.front();
    dq.pop_front();
    sum ^= removed;
    cur = (cur*a + b)%c;
    ans ^= sum;
  }
  cout << ans << endl;
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