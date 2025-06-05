#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;
 
void Solve(){
  int n; cin>> n;
  unordered_map<int,int> cnt;
  unordered_map<int,int> mp;
  vector<int> count1(n,0);
  for(int i = 0; i < n; i++){
    int k; cin>> k;
    for(int j = 0; j <k; j++){
      int x; cin>> x;
      if(cnt[x] == 0){
        mp[x] = i;
        count1[i]++;
      }else if(cnt[x] == 1){
        count1[mp[x]]--;
        mp.erase(x);
      }
      if(cnt[x] < 2)cnt[x]++;
    }
  }
  int ans = 0;
  for(int i = 0; i< n; i++){
    ans += (count1[i] > 0);
  }
  if(ans <= n - 1)cout << "YES";
  else cout << "NO";
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