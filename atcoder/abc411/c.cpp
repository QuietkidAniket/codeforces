/**
 *    author: Anicetus_7
 *    created: 2025-06-23 11:42:35
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,q; cin>> n>>q;
  vector<int> query(q);
  for(auto& x: query)cin>> x;

  vector<int> arr(n+2,0);
  arr[0] =arr[n+1] = -1;
  int cnt = 0;
  for(int i= 0; i <q; i++){
    int x = query[i];
    arr[x] = 1 - arr[x];
    if(arr[x] ==1){
      if((arr[x-1] != 1) && (arr[x+1] != 1))cnt++;
      else if((arr[x-1] == 1) && (arr[x+1] == 1))cnt--;
    }else{
      if((arr[x-1] != 1) && (arr[x+1] != 1))cnt--;
      else if((arr[x-1] == 1) && (arr[x+1] == 1))cnt++;
    }
    cout << cnt << endl;
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
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}