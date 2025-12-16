/**
 *    author: Anicetus_7
 *    created: 2025-12-04 21:08:46
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int a[100005];
void Solve(){
  int n,m,k; cin>>n>>m>>k;
  for(int i = 1; i <= n;i++)cin>>a[i];
  
  vector<vector<int>> vec(m+1);
  for(int i = 1; i<=m; i++){
    int l,r, d; cin>>l>>r>>d;
    vec[i] = {l,r, d};
  }
  
  int range[m+2];
  memset(range, 0, sizeof range);
  for(int i = 1; i<=k; i++){
    int l,r; cin>>l>>r;
    range[l] += 1;
    range[r+1] -= 1;
  }
  
  int add[n+2];
  memset(add, 0, sizeof add);
  for(int i =1; i <= m; i++){
    range[i] += range[i-1]; // just need to update range from 1 to m and not n (as per question)

    add[vec[i][0]] += range[i]* vec[i][2];
    add[vec[i][1] + 1] -= range[i]*vec[i][2];
  }
  for(int i =1; i <= n; i++){
    add[i] += add[i-1];
    cout << add[i] + a[i] << " ";
  }
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