/**
 *    author: Anicetus_7
 *    created: 2025-09-13 17:56:45
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(1005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


char a[MAX][MAX];
int pref[MAX][MAX];

void Solve(){
  int n; cin>> n;
  int q; cin>>q;
  memset(pref, 0, sizeof pref);
  for(int i = 1;i <= n ;i++){
    for(int j =1; j <= n; j++){
      cin>>a[i][j];
    }
  }

  for(int i =1; i <=n ;i++){
    for(int j = 1;j <= n ;j++){
      pref[i][j] = pref[i-1][j] + pref[i][j-1] + (a[i][j] == '*') -  pref[i-1][j-1];
    }
  }

  for(int i = 0; i < q ;i++){
    int r1,c1; cin>>r1>>c1;
    int r2,c2; cin>>r2>>c2;
    cout << pref[r2][c2]- pref[r2][c1-1] - pref[r1-1][c2] + pref[r1-1][c1-1] << endl;
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