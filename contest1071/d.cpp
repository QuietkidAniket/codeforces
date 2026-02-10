/**
 *    author: Anicetus_7
 *    created: 2025-12-23 20:48:19
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n;cin >> n;
  set<int> st;
  int res = (1ll<<n)-1;
  for(int i =0; i < n;i++){
    cout << res << " ";
    st.insert(res);
    for(int j = res; j < (1ll<<n); j++){
      if(st.count(j))continue;
      if((res&j) == res){
        cout << j << " ";
        st.insert(j);
      }
    }
    res >>=1;
  }
  for(int i = 0; i < (1ll<<n); i++)if(!st.count(i))cout<< i << " "; 
  cout <<endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main()
{
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    // cout << "Case #" << i << ": \n";
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}