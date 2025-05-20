#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

ll findd(int x, int y, int n){
  ll d= 0ll;
  x--, y--;
  for(int k = n-1; k>=0; k--){
    int mid = 1 << (k);
    const ll z = 1ll << (2*k);
    if(x < mid && y < mid);
    else if(x >= mid && y >= mid)x -= mid, y -= mid, d += z;
    else if(x < mid && y >= mid) y -= mid, d+= 3ll*z;
    else x-=mid, d+= 2ll*z;
  }
  return d+1;
}

vector<ll> findxy(int n, ll d){
  d--;
  int x = 0, y = 0;
  for(int k = n -1; k >= 0; k--){
    int mid = 1 << k;
    const ll z = 1ll << (2*k);
    ll v = d / z;
    if(v == 0);
    else if(v == 1ll)x += mid, y += mid; 
    else if(v == 2ll)x += mid;
    else y += mid;
    d = d % z;
  }
  return {x+1, y+1};
}


void Solve(){
  int n; cin>> n;

  int q; cin>> q;

  for(int i = 0; i < q; i++){
    string s; cin>> s;
    if(s == "<-"){ // element d where?
      ll d; cin>> d;
      auto vec = findxy(n, d);
      cout << vec[0] <<" " << vec[1] << endl;
    }else{  // what element at (x,y)?
      int x, y; cin>> x>>y;
      cout << findd(x,y,n) << endl;
    }
  }

}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
  freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  // cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}