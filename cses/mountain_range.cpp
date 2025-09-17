/**
 *    author: Anicetus_7
 *    created: 2025-09-17 14:46:08
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int find(vector<int>& a){
  stack<pair<int,int>> stk;
  stk.push({INF, 0});

  for(int x: a){
    int cnt =1;
    while(stk.size() > 1 && stk.top().first < x){
      cnt += stk.top().second;
      stk.pop();
    }
    if(stk.size() == 1){
      auto t = stk.top();
      stk.pop();
      stk.push({INF, max(t.second, cnt)});
      stk.push({x, 1ll});
    }else{
      stk.push({x, cnt});
    }
  }
  int cnt =0;
  while(stk.size() > 1){
    cnt += stk.top().second;
    stk.pop();
  }
  int ans = max(stk.top().second, cnt);
  return ans;
}


void Solve(){
  int n; cin>>n;
  vector<int> a(n);
  for(auto& x : a)cin>> x;

  int ans1  = find(a);
  reverse(a.begin(), a.end());
  int ans2  = find(a);
  cout << max(ans1, ans2) << endl;
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