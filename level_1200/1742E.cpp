#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef unsigned long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n; cin>> n;
  int q; cin>> q;
  int arr[n];
  ll prefix[n+1];
  prefix[0]= 0ll;

  int prefix_max[n+1];
  prefix_max[0]= 0;
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
    // store the prefix sum
    prefix[i+1] = prefix[i] + arr[i];
    // store the prefix maximum from left to till ith element
    prefix_max[i+1] = max(prefix_max[i], arr[i]);
  }
  int query[q];
  for(int i = 0; i< q; i++)
  {
    cin >> query[i];
  }
  
  for(const auto& k : query){
    // search for the maximum a[i] equal to less than k
    int low = 0, high = n;
    while(low<= high){
      int mid = (low + high)/2;
      if(prefix_max[mid] <= k){
        low = mid +1;
      }else{
        high = mid -1;
      }
    }
    cout << prefix[high]<<" ";
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