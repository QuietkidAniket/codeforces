/**
 *    author: Anicetus_7
 *    created: 2025-07-04 02:35:43
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
  vector<int> freq(n+1, 0);
  for(int i = 0; i < n; i++){
    freq[a[i]]++;
  }
  cout << 1 << " ";
  for(int k =1; k <= n; k++){
    int cnt = 0, sum = 0, total = 0;
    for(int num = 0; num <= n; num++){
      if(freq[num] == 0)continue;
      if(freq[num] <= k){
        if(freq[num] < k){
          cnt += (sum + (n- total) >= k);
        }else{
          cnt++;
        }
      }
      sum += freq[num] -1;
      total += freq[num];
    }
    cout << cnt  << " ";
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