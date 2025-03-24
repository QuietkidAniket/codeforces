#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n;
  cin>> n;

  // int arr[n*(n-1)];

  map<int,int> mp;
  for(int i = 0; i< n*(n-1)/2; i++)
  { 
    int x;
    cin>> x;
    mp[x]++;
  }

  vector<int> ans;

  int count = 1;
  for(auto it = mp.begin(); it != mp.end(); it++){
    ans.push_back(it->first);
    int n_time = (it->second) - (n - count++);
    if(n_time == 0)continue;
    while(n_time-- > 1)ans.push_back(it->first);
  }
  if(ans.size() < n){
    while(ans.size() != n){  
      ans.push_back( mp.rbegin()->first);
    }
  }

  for(int i = 0; i< n; i++)
  {
    cout << ans[i] << " "; 
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