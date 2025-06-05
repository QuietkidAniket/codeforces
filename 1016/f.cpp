#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n,m; cin>> n>>m;
  vector<string> a(n);
  bitset<500> need;
  for(int i =0; i < n; i++){
    cin>> a[i];
  }

  // vector<vector<string>> b(m, vector<string>(n));
  vector<bitset<500>> id(m);
  int k = 0;
  for(int i = 0; i< m; i++)
  {
   for(int j = 0; j< n; j++)
   {
    string x;
    cin>> x;
    if(x == a[j]){
      id[i].set(j);
      need.set(j);
    }
   } 
   k = max(k, (int)id[i].count());
  }
  if(need.count() != n){
    cout << -1;
    return;
  }
  cout << n + (n-k)*2;
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