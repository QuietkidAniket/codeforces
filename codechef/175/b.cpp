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
  vector<string>arr(3);
  for(int i = 0; i< 3; i++)cin >> arr[i];
  
  if(n == 1){cout << 0; return;}
  vector<int> num_zeroes(3);
  int total_zeroes = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j< n; j++)if(arr[i][j] == '0'){num_zeroes[i]++; total_zeroes++;}
  }
  
  if(total_zeroes % n != 0){
    cout << -1;
    return;
  }

  vector<int> ans(3);

  for(int i = 0; i< 3; i++)
  {
    ans[i] = min(n-num_zeroes[i], num_zeroes[i]); 
  }
  sort(ans.begin(), ans.end());
  cout << ans[0] + ans[1];
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