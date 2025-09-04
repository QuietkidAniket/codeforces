/**
 *    author: Anicetus_7
 *    created: 2025-07-27 20:04:34
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int bin(multiset<int>& st, int c, int prod){
  vector<int> a(st.begin(), st.end());
  int l = 0, h = a.size()-1, ans = -1;
  while(l <= h){
    int mid = (l+h)/2;
    if(a[mid]*prod <= c){
      ans = mid;
      l = mid +1;
    }else h = mid -1;
  }
  return (ans == -1 ? -1 : a[ans]);
}

void Solve(){
  int n, c;
  cin >> n >> c;
  vector<int> a(n);
  for(auto& x : a) cin >> x;

  multiset<int> st(a.begin(), a.end());
  int prod = 1, cnt = 0;

  for(int i = 0; i < n; i++){
    int res = bin(st, c, prod);
    if(res == -1 || res * prod > c) {
      cnt++;
    } else {
      st.erase(st.find(res));
    }
    prod *= 2;
  }
  cout << cnt << '\n';
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}