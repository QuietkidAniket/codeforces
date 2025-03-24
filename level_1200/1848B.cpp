#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n, k;
  cin>> n>>k;
  int arr[n];
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
  }

  vector<vector<int>> intervals(k+1, vector<int>(2,0));
  vector<int> prev(k+1,-1);
  for(int i = 0; i <= n; i++){
      if(i == n){
        for(int x = 1; x <= k; x++){
          if(intervals[x][1] < i - prev[x] -1){
            intervals[x][0] = intervals[x][1];
            intervals[x][1] = i - prev[x] -1;
          }else if(intervals[x][0] < i - prev[x] -1){
            intervals[x][0] = i- prev[x]-1;
          }
        }
      }else{
        int x = arr[i];
        if(intervals[x][1] < i - prev[x] -1){
          intervals[x][0] = intervals[x][1];
          intervals[x][1] = i - prev[x] -1;
        }else if(intervals[x][0] < i - prev[x] -1){
          intervals[x][0] = i- prev[x]-1;
        }
        prev[x] = i;
      }
  }
  int ans = INT_MAX;
  for(int x = 1; x <=k ; x++){
    int interval = (int)intervals[x][1]/2;
    intervals[x][1] = interval;
    ans = min(ans, max(intervals[x][0], intervals[x][1]));
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