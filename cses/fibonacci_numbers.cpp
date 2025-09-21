/**
 *    author: Anicetus_7
 *    created: 2025-09-21 16:04:58
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

struct matrix{
  int n, m;
  vector<vector<int>> mat;
  
  matrix(): n(0), m(0) {}
  matrix(int n_, int m_, const vector<vector<int>>& mat_): n(n_), m(m_), mat(mat_){}
  
  /**
   * evaluates C(n,m) = A(n,p) x B(p,m)
   * C[i][j]= ∑ A[i][k] * B[k][j]
  */
  matrix operator*(const matrix& B){
    const auto A = *this;
    matrix C = {A.n, B.m, vector<vector<int>>(A.n, vector<int>(B.m, 0))};
    for(int i =0 ; i < A.n; i++){
      for(int j = 0; j < B.m; j++){
        for(int k = 0; k < A.m; k++){
          C.mat[i][j] += A.mat[i][k]*B.mat[k][j];
        }
        C.mat[i][j] %= MOD;
      }
    }  
    return C;
  }
  
};

matrix matrixpow(matrix base, int exp){
  matrix res = {2,2 ,{{1,0}, {0,1}}};
  while(exp > 0){
    if(exp&1){
      res = res * base;
    }
    base = base* base;
    exp >>=1;
  }
  return res;
}

void Solve() {
  int n; cin >> n;
  if (n == 0) { cout << 0 << "\n"; return; }
  if (n == 1) { cout << 1 << "\n"; return; }

  matrix fibMat(2, 2, {{1,1},{1,0}});
  auto F_n = matrixpow(fibMat, n-1);
  cout << F_n.mat[0][0] % MOD << "\n"; 
}


// void Solve(){
  // int n; cin>>n;
  // Dynamic Programming
  // int dp[3] = {0};
  // dp[1] = dp[0] = 1;

  // for(int i =2; i < n; i++){
  //   dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3];
  //   dp[i%3] %= MOD;
  // }
// }

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