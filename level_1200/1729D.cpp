#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;


void Solve(){
  int n; cin>> n;
  int arr[n];
  for(int i = 0; i< n; i++)
  {
   cin>> arr[i] ;
  }
  for(int i = 0; i< n; i++)
  {
    int x; cin >> x;
    arr[i]  = x - arr[i];
  }

  // sort the (yi - xi)
  sort(arr, arr+n);
  reverse(arr, arr+n);
  int left = 0, right = n-1, ans = 0;

  // for each richest friend we find the poorest friend with whom they can pair up with.
  for(; left< n; left++){
    while(left < right && arr[left] + arr[right] < 0)right--;
    if(left >= right)break;
    ans++;
    right--;
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