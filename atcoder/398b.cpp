#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = false;
static const int mod = 1e9 + 7;

void Solve(){
  int arr[7];
  unordered_map<int,int> mp;
  for(int i = 0; i< 7; i++){
    cin>> arr[i];
    mp[arr[i]]++;
  }
  bool a= false, b = false;
  for(const auto& [x, freq] : mp){
    if(freq >= 3 && !a)a = true;
    else if(freq >= 2 && !b)b = true;
  }
  if(a && b) cout <<  "Yes";
  else cout << "No";
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