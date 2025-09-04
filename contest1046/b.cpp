/**
 *    author: Anicetus_7
 *    created: 2025-08-28 20:40:54
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,k; cin>>n>>k;
  string s; cin>>s;

  int zeros = 0, ones  = 0;

  int cnt[n+1][2];
  cnt[0][0] = cnt[0][1]=0;
  for(int i =0; i <n; i++){
    if(s[i] == '1'){
      cnt[i+1][1] = cnt[i][1]+1;
      cnt[i+1][0] = cnt[i][0];
    }else{
      cnt[i+1][0] = cnt[i][0]+1;
      cnt[i+1][1] = cnt[i][1];
    }
  }
  for(int i = k-1; i< n; i++)
  {
    if(cnt[i+1][0]- cnt[i-k+1][0] == 0){
      cout << "NO\n";
      return;
    }
  }
  int ans[n];
  cout << "YES\n";
  int op = 1, zp  = cnt[n][1]+1;
  for(int i = 0; i< n; i++)
  {
    if(s[i] == '1')ans[i] = op++;
    else ans[i] = zp++;
  }
  for(auto& x : ans)cout<<  x << " ";
  cout << endl;
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