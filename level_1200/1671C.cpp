#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n, x; cin>> n>> x;

  int arr[n];
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
  }
  
  sort(arr, arr+n);
  ll prefix[n+1];
  prefix[0] = 0;
  for(int i = 0; i< n; i++)
  {
    prefix[i+1] = prefix[i] + arr[i];
  }
  // for the maximum k, we need to add 1 as 0th day is also counted
  ll ans = 0, prev= -1ll;
  // iterate through the items and calculate the number of days we will be buying all the items till the ith item
  for(int i = 1; i <= n; i--)
  { 
    if(x < prefix[i])continue;
    // we find the kth day
    ll k = (x- prefix[i])/i;
    ans += (ll)( k - prev) * i;
    prev = k;
  }
  cout << ans;
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