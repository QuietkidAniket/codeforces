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
  vector<pair<int,int>> a1(n);
  vector<pair<int,int>> a2(n);
  vector<pair<int,int>> a3(n);

  for(int i = 0; i< n; i++)
  {
    cin>> a1[i].first;
    a1[i].second = i;
  }
  for(int i = 0; i< n; i++)
  {
    a2[i].second = i;
    cin>> a2[i].first;
  }
  for(int i = 0; i< n; i++)
  {
    a3[i].second = i;
    cin>> a3[i].first;
  }

  sort(a1.rbegin(), a1.rend());
  sort(a2.rbegin(), a2.rend());
  sort(a3.rbegin(), a3.rend());

  int ans = 0;

  for(int i = 0; i< 3; i++){
    for(int j = 0 ; j < 3; j++){
      if(a1[i].second == a2[j].second)continue;
      for(int k = 0 ; k < 3; k++){
        if(a1[i].second == a3[k].second || a2[j].second == a3[k].second )continue;
        ans = max(ans, a1[i].first +  a2[j].first + a3[k].first);
      }
    }
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