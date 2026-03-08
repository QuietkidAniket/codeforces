/**
 *    author: Anicetus_7
 *    created: 2026-01-25 20:41:25
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(3e5+5)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
  int n; cin>>n;
  unordered_set<int> st;
  for(int i =0 ;i<n; i++){
    int x; cin>>x;
    st.insert(x);
  }
  
  vector<int> dp(n+5, -1);
  
  vector<vector<int>> divisors(n+5);
  for(int i = 2; i <= n; i++){
    for(int j = i; j <= n; j+=i)divisors[j].push_back(i);
  }

  function<int(int)> f= [&](int num)->int{
    if(num <= 1)return 0;
    if(dp[num] != -1)return dp[num];
    int res = INF;
    for(int divisor : divisors[num]){
      if(!st.count(divisor))continue;
      res = min(res, f(num/divisor) + 1);
    }
    return dp[num] = res;
  };

  cout << (st.count(1)? 1: -1) << " ";
  for(int i =2;i <= n; i++){
    int res  = f(i);
    res= res==INF? -1 : res;
    cout <<  res << " ";
  }
  cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  // generate();
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