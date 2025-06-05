#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;


ll fib(ll n){
  int dp[3];
  dp[0]= 0;
  dp[1] = 1;
  for(int i = 2; i <=n; i++){
    dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3];
  }
  return dp[n%3];
}

void Solve(){
  int n, m; cin>> n>>m;
  ll c1 = fib(n+1); 
  ll c2 = c1 + fib(n);
  for(int i=0; i < m;i++){
    vector<int> box(3);
    cin>> box[0] >> box[1] >> box[2];
    if(box[0] < c1 || box[1] < c1 || box[2] < c1){
      cout << "0";
      continue;
    }
    sort(box.rbegin(), box.rend());
    if(box[0] < c2)cout << "0";
    else cout << "1";
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
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}