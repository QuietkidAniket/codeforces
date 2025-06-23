/**
 *    author:  Anicetus_7
 *    created: 2025-06-19 17:56:47
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct A{
  int l, r;
};

ostream& operator<<(ostream& o, A& a){
  o << a.l  << ", " << a.r;
  return o;
}

void Solve(){
  int n, x, m; cin>> n>> x>>m;

  vector<A> arr(m);
  for(int i = 0; i<m ;i++){
    cin>> arr[i].l >> arr[i].r;
  }


  int left = x, right  = x;
  bool flag = false;
  for(int i= 0; i <m ;i++){
    if(!(arr[i].r < left || arr[i].l > right)){
      left = min(arr[i].l, left);
      right = max(arr[i].r, right);
    }
  }

  cout << right- left +1 << endl;
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  int tt = clock();
  #endif
  
  int t = 1;
  cin>> t;
  while(t--){
  Solve();
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}