/**
 *    author: Anicetus_7
 *    created: 2025-07-03 17:50:09
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

bool check(const vector<int>& arr, int target, int k){
  int n=  arr.size();
  for(int idx = 0; idx < n; idx++){
    int t = target, i = idx, sum = 0;
    bool flag = false;
    while(i < n && arr[i] < t){
      sum += (t - arr[i]);
      i++; t--;
    }
    if(i == n){
      continue;
    }
    if(sum <= k)return true;
  }
  return false;
}


void Solve(){
  int n, k; cin>>n >>k;
  int ans =0;
  vector<int> arr(n); for(auto& x :arr){cin>>x; ans = max(ans, x);}
  int l = 0, r = 2*1e8;
  while(l <= r){
    int mid  = (l+r)/2;
    if(check(arr, mid, k)){
      ans = max(ans,mid);
      l = mid+1;
    }else{
      r = mid -1;
    }
  }
  cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++)
    {
        cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
