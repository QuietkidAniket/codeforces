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
   cin>> arr[i];
  }
  map<int,int> mp;

  for(int i = 0 ; i < n; i++){
    mp[arr[i]]++;
  } 
  int prev = 0;
  int prev_x = INT_MIN;
  int ans = 0;
  for(const auto& [x, freq] : mp){
    if(prev_x +1 == x){
      ans += max(freq-prev,0);
    }else{
      ans += freq;
    }
    prev_x = x;
    prev = freq;
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