#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n, W; cin>> n >> W;
  int cnt[31];
  memset(cnt, 0, sizeof cnt);
  vector<int> w(n);
  int mask = 0;
  for(int i = 0; i< n; i++)
  {
    cin >> w[i];
    mask |= w[i];
    int ind = floor(log2(w[i]));
    cnt[ind]++;
  }
  int levels = 0;
  while(mask > 0){
    // fill each level to the maximum length
    int length = W;
    for(int i =30; i>=0 && length > 0; i--){
      if(cnt[i] == 0)continue;
      else{
        int ntimes = length / (1 << i);
        length = length - min(ntimes, cnt[i])*(1<<i);
        cnt[i]-= min(ntimes, cnt[i]);
        if(cnt[i] == 0)mask ^= (1 << i);
      }
    }
    levels++;
  }
  cout << levels;
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