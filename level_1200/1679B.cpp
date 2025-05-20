#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef unsigned long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = false;
static const int mod = 1e9 + 7;


void Solve(){
  int n, q; cin>> n>> q;
  vector<int> arr(n);
  ll sum = 0ll;
  for(int i = 0; i< n; i++)
  {
    cin>> arr[i]; 
    sum += arr[i];
  }
  
  // first query index
  vector<int> lastfirstquery(n,0);
  // second query index, value
  int lastsecondquery = 0, lastsecondqueryvalue = 0;
  for (int i = 1; i <= q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
        int ind, x; cin >> ind >> x;
        ind--;

        if (lastfirstquery[ind] < lastsecondquery) {
          sum -= lastsecondqueryvalue;
        }else sum -= arr[ind];
        sum += x;
        arr[ind] = x;
        lastfirstquery[ind] = i;  

    } else if (t == 2) {
        int x;cin >> x;

        sum = (ll)x * n;
        lastsecondquery = i;
        lastsecondqueryvalue = x;
      }
      cout << sum << endl;
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