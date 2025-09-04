/**
 *    author: Anicetus_7
 *    created: 2025-06-23 21:33:32
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n ; cin>>n;
  vector<int> arr(n);
  for(auto& x : arr)cin>>x;
  sort(arr.begin(), arr.end());
  int mx = arr.back();
  int cnt  = 0; 
  
  // two pointer
  for(int k= 0; k< n; k++){
    int i = 0,j = k-1;
    int target = max(mx- arr[k], arr[k]);

    while(i < j){
      if(arr[i] + arr[j]  > target){
        cnt += j-i;
        j--;
      }else{
        i++;
      }
    }
  }
  cout << cnt << endl;
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

// Binary search 
  // for(int i = 0; i < n; i++) {
  //   for(int j = i + 1; j < n; j++) {
  //     int a = arr[i], b = arr[j];
  //     int low = mx - (a + b);
  //     int high = a + b;

  //     auto l = upper_bound(arr.begin() + j + 1, arr.end(), low);
  //     auto r = lower_bound(arr.begin() + j + 1, arr.end(), high);

  //     int temp = r - l;
  //     cnt += max(0ll, temp);
  //   }
  // }