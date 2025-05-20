#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n,m; cin>> n >> m;
  int arr[m];

  for(int i = 0; i< m; i++)
  { 
    cin>>arr[i];
  }
  sort(arr, arr+m);
  vector<int> uninfected(m-1);
  for(int i = 1; i<m; i++)
  {
    uninfected[i-1] =arr[i] - arr[i-1] -1;
  }

  int round_trip = n-1 - arr[m-1] + arr[0];
  if(round_trip > 0)uninfected.push_back(round_trip);

  // ascending order of segment lengths so that we can focus of larger segments first
  sort(uninfected.rbegin(), uninfected.rend());

  // stores the total number of uninfected houses
  ll ans = 0ll;
  // count * -2 - 1 is the relation for completely sealing two ends
  // and then count is increased by 2 as after every two days we focus on another segment
  ll  count = 0ll;
  for(int i = 0; i <  uninfected.size(); i++, count+=2){
    if(uninfected[i] - count* 2 > 0){
      ll amt = max(uninfected[i] - count* 2 - 1,1ll);
      ans += amt;
    }
  }
  cout << n - ans;
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