/**
 *    author: Anicetus_7
 *    created: 2025-12-03 12:10:13
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(2005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

char a[MAX][MAX];

int left_edges[MAX][MAX];
int up_edges[MAX][MAX];
int vertices[MAX][MAX];


void Solve(){
  int n,m,q; cin>>n>>m>>q;
  for(int i  = 1;i <= n ;i++){
    for(int j = 1; j <= m; j++){
      cin>> a[i][j];
      vertices[i][j] =  vertices[i-1][j] + vertices[i][j-1] - vertices[i-1][j-1] + (a[i][j]=='1');
    }
  }
  for(int i  = 1;i <= n ;i++){
    for(int j = 1; j <= m; j++){
      left_edges[i][j] =  left_edges[i-1][j]+ left_edges[i][j-1] - left_edges[i-1][j-1];
      up_edges[i][j] =  up_edges[i-1][j]+ up_edges[i][j-1] - up_edges[i-1][j-1];
      if(a[i][j] == '1'){
        left_edges[i][j] += (a[i][j-1]=='1');
        up_edges[i][j] += (a[i-1][j]=='1');
      }
    }
  }
  
  auto query = [&](int (*z)[MAX], int r1, int c1, int r2, int c2){
    return z[r2][c2] - z[r1-1][c2]-  z[r2][c1-1] +  z[r1-1][c1-1];
  };
  
  for(int i =0 ;i <q ; i++){
    int r1, c1, r2, c2; cin>>r1>>c1>> r2 >>c2;
    int v = query(vertices, r1, c1, r2, c2);
    int le = query(left_edges, r1, c1+1, r2, c2 );
    int ue = query(up_edges, r1+1, c1, r2, c2);
    cout << v-le-ue <<endl;
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