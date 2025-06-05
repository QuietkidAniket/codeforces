#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

int bin_search(const vector<int>& arr, int k){
  int low = 0, high = k-1;
  int ans = -1;
  while(low <= high){
    int mid = (low + high)>> 1;
    if(arr[mid] >= (k-mid)){
      high = mid -1;
      ans = mid;
    }else{
      low = mid + 1;
    }
  }
  return k - (ans);
}

void Solve(){
  int n; cin>> n;
  vector<int> arr(n);
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
  }

  for(int k =1;k <= n; k++){
    cout << bin_search(arr, k) << " ";
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