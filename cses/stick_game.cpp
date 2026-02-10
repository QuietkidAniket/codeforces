/**
 * author: Anicetus_7
 * created: 2026-01-24 08:30:24
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void Solve(){
 int n; cin>>n;
 int k; cin>>k;
 vector<int> p(k);

 for(auto& x : p) cin >> x;

 vector<int> dp(n+1); 
 vector<int> vis(k+1,0);

 dp[0] = 0;
    

 for(int i =1;i <= n; i++){
     for(int x : p){
         if(i-x<0)continue;
         int g = dp[i-x];
         if(g <= k){
             vis[g] = i;
         }
     }
     int mex = 0;
     while(vis[mex] == i)mex++;
     dp[i] = mex;
     cout << (dp[i]==0? 'L' : 'W'); 
 }
 cout << endl;

}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin >> t;
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

