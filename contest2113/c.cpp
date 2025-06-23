/**
 *    author:  Anicetus_7
 *    created: 2025-06-15 17:09:57
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, m, k; cin>> n>> m >>k;
  vector<vector<int>> prefix(n, vector<int>(m+1,0ll));
  vector<pair<int,int>> empty;
  int totalgold = 0;
  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < m; j++){
      char x;cin>> x;
      if(x == '.')empty.push_back({i,j});
      if(x=='g')totalgold++;
      prefix[i][j+1] = prefix[i][j] + (x=='g');
    }
  }
  auto calculate_loss = [&](int i , int j){
    int loss = 0 ;
    for(int r = max(i- k +1,0ll); r <= min(n-1, i+k-1); r++){
      int minc = max(j- k+1,0ll),  maxc = min(m-1, j+k-1);
      loss += prefix[r][maxc+1] - prefix[r][minc];
    }
    return loss;
  };

  int minloss = 1e9+1;
  for(const auto& [x, y] : empty){
    minloss = min(minloss, calculate_loss(x,y));
  }
  cout << totalgold - minloss<<'\n';
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



