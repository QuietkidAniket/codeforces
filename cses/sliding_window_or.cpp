/**
 *    author: Anicetus_7
 *    created: 2026-01-17 18:15:32
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

  deque<int> dq;
  vector<int> p(32, 0);
  auto update = [&](int num, int k){
    int cur =0;
    for(int bit =0 ;bit < 30; bit++){
      if(num&(1<<bit)){
        if(add)p[bit]++;
        else p[bit]--;
        if(p[bit] > 0)cur |= (1<<bit);
        if(p[bit] <= 0)cur |= (1<<bit);
      }
    }
    return cur;
  };
  int cur = x;
  int sum = 0;
  int ans = 0;
  for(int i = 1;i <= k; i++){
    dq.push_back(cur);
    update(cur, true);
    ans |= cur;
    cur = (cur*a + b)%c;
  }
  
  for(int i = k+1;i <= n; i++){
    sum |= cur;
    update(cur, true);
    dq.push_back(cur);
    int removed = dq.front();
    dq.pop_front();
    int res = update(removed, false);
    cur = (cur*a + b)%c;
    ans ^= res;
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