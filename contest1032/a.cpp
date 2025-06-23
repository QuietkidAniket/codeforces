/**
 *    author:  Anicetus_7
 *    created: 2025-06-17 20:04:58
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, s; cin>>n>>s;
  vector<int> x(n);
  for(int i = 0; i< n; i++)
  {
   cin>> x[i];
  }
  int pos= 0, neg =0;
  if(s <= x.back())pos = x.back() - s;
  if(x[0]<= s)neg = s - x[0];

  if(pos == 0){
    cout << neg << endl;
  }else if(neg == 0){
    cout << pos << endl;
  }else{
    int temp = min(pos, neg);
    int temp2 = max(pos, neg);
    cout << 2*temp +temp2 << endl;
  }
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