#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  string a, b;
  cin>> a;
  cin>> b;
  int ptra = a.size()-1;
  int ptrb = b.size()-1;
  unordered_map<int, bool> mp;
  while(ptra>= 0 && ptrb >=0){
    if(b[ptrb] == a[ptra]){
      mp[ptra] = true;
      ptra--;
      ptrb--;
    }else{
      ptra--;
    }
  }
  
  if(ptrb != -1){
    cout << "-1";
    return;
  }
  ll score  = 0, index = 1;
  for(int i = 0; i < a.size(); i++){
    if(mp.find(i) != mp.end()){
      index++;
    }else{
      score += index;
    }
  }
  cout << score;
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