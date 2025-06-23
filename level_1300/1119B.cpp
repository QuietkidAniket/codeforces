/**
 *    author: Anicetus_7
 *    created: 2025-06-20 23:28:27
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

  int n, k;
  bool check(vector<int>& l, int s){
    vector<int> arr(l.begin(), l.begin()+s);
    sort(arr.rbegin(), arr.rend());
    int height =0;
    for(int i =0; i<s; i+=2){
      int a =0, b =0;
      if(i+1 < s){
        a =max(arr[i], arr[i+1]);
        b =min(arr[i], arr[i+1]);
      }else{
        a = arr[i];
      }
      if(a + height <= k){
        height += a;
      }else return false;
    }
    return true;
  }

  int binsearch(vector<int>& arr){
    int low = 1, high = n;
    int ans =1;
    while(low <= high){
      int mid =(low+high)>>1;
      if(check(arr, mid)){
        low = mid +1;
        ans = mid;
      }else{
        high = mid -1;
      }
    }
    return ans;

  }


void Solve(){
  cin>> n>>k;  

  vector<int> a(n);
  for(int i = 0; i <n ;i++){
    cin>> a[i];
  }
  cout << binsearch(a) << '\n';
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