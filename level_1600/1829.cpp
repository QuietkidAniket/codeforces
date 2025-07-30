/**
 *    author: Anicetus_7
 *    created: 2025-07-29 12:00:06
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int M = 2024;
const int N = 1e6+1;

vector<vector<int>> p(M), sum(M);
pair<int,int> idx[N];

void generate(){
  int c = 0;
  for(int i = 1; i< M; i++)
  {
    p[i].resize(i+1,0);
   for(int j = 1; j<=i;  j++)
   {
      c++;
      if(c>= N)break;
      idx[c] = {i,j};
      p[i][j] = c*c;
      if(j <= i-1)p[i][j] += p[i-1][j];
   } 
  }

  for(int i = 1; i< M; i++)
  {
    sum[i].resize(i+1,0);
    for(int j = 1; j<= i; j++){
      sum[i][j] = p[i][j];
      if(j>1) sum[i][j] += sum[i-1][j-1];
    }
  }
}

void Solve(){
  int x; 
  cin>>x;
  auto res = idx[x];
  cout << sum[res.f][res.s] << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  generate();
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