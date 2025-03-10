#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n, m, k;
  cin>> n>>m>>k;
  if(max(m,n)< k){
    cout << "-1";
    return;
  }
  int a =abs(n-m);
  if(a >k){
    cout << "-1";
    return;
  }
  string res= "";
  char larger, smaller;
  if(n > m){ 
    swap(n,m);
    larger = '0';
    smaller = '1';
  }else{
    larger = '1';
    smaller = '0';
  }

  // m is larger element
  int curr_m = 1, curr_n = 0;
  cout << larger;
  while(curr_m != m || curr_n !=n){
    // try placing the larger element first
    if(abs(curr_m+1 - curr_n) <= k && curr_m!=m){
      res.push_back(larger);
      curr_m++;
    }else{// try placing the smaller element
      if(curr_n == n)break;
      res.push_back(smaller);
      curr_n++;
    }
  }
  cout << res;
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