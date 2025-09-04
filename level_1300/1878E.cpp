/**
 *    author: Anicetus_7
 *    created: 2025-07-09 21:28:17
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> a(n); for(auto& x : a)cin>>x;
  int nq; cin>> nq;
  vector<pair<int,int>> q(nq, {0,0}); 
  for(auto& [l,k] : q)cin>>l>>k;
  vector<vector<int>> prefix(n+1, vector<int>(32,0));

  for(int i = 0; i< n; i++)
  {
    for(int j = 0; j < 32; j++){
      prefix[i+1][j] = prefix[i][j];
      if(a[i] & (1<<j)){
        prefix[i+1][j]++;
      }
    } 
  }
  auto check = [&](int l, int r){
    int sum = 0;
    for(int i = 0; i < 32; i++){
      if(prefix[r+1][i] - prefix[l][i] >= r-l+1){
        sum += (1<<i);
      }
    }
    return sum;
  };

  for(auto& [l , k] : q){
    l--;
    int low =l, high = n-1, ans = -1;
    while(low <= high){
      int mid  = (low +high)>>1;
      if(check(l, mid) >= k){
        ans= mid;
        low = mid +1;
      }else high = mid-1;
    }
    cout << (ans == -1? -1:ans+1) << " ";
  }
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
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}