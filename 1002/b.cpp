#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n, k;
  cin>> n>>k;
  vector<int> arr(n);
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
  }
  
  // k is even
  // if k == n then all are unique subarrays
  // if k < n then we need to partition such that
  // 1s lies in 1st subarray and number greater than 1 lie in 2nd subarray 
  // in which case we output answer as 1 (as there is first number greater than 1 in 2nd subarray)
  // if its not possible then we output answer as 2
  if(k == n){
    int index = 1;
    for(int i = 1; i < n; i+=2, index++){
      if(arr[i] != index){
        cout<< index;
        return;
      }
    } 
    cout<< index;
  }else{
    for(int i = 1; i <= n-k + 1; i++){
      if(arr[i] != 1){
        cout << 1;
        return;
      }
    } 
    cout << 2;
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
  freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}