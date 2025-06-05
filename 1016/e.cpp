#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

int num[1 << 18];


bool check(const vector<int>& arr, int k, int min_mex){
  for(int j = 0 ; j < min_mex; j++)num[j] = 0;
  
  int cnt = 0;
  int temp = min_mex;
  for(int i = 0; i < arr.size(); i++){
    if(arr[i] < min_mex){
      if(!num[arr[i]]++)temp--;
    }
    if(temp == 0){
      cnt++;
      temp = min_mex;
      for(int j = 0 ; j < min_mex; j++)num[j] = 0;
    }
  }
  return cnt >= k;
}


void Solve(){
  int n, k; cin>> n>>k;
  vector<int> arr(n);
  int n_zeros = 0;
  int max_elem = 0;
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
    if(!arr[i])n_zeros++;
    max_elem = max(max_elem, arr[i]);
  }
  if(n_zeros < k){
    cout << 0;
  }else{
    int low = 0, high = n/k +1, ans = 0;
    while(low <= high){
      int mid = (low + high)/2;
      if(check(arr, k, mid)){
        ans = mid;
        low = mid + 1;
      }else high = mid - 1;
    }
    cout << ans;
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