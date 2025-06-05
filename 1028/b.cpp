#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const ll mod = 998244353ll;

ll power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1)res = res * base %mod;
        base = base * base %mod;
        exp >>= 1;
    }
    return res;
}

void Solve(){
  int n; cin>> n;
  vector<int> p(n), q(n);
  for(int i = 0; i< n; i++)cin>>p[i];
  for(int i = 0; i< n; i++)cin>>q[i]; 
  vector<int> r(n);
  ll maxp = -1, maxq = -1, maxpind = 0, maxqind = 0;
  for(int i = 0; i < n; i++){
    if(maxp < p[i]){maxp = p[i]; maxpind = i;}
    if(maxq < q[i]){maxq = q[i]; maxqind = i;}
    if(maxp > maxq){
      r[i] = (power(2ll, maxp) + power(2ll, q[i - maxpind]))%mod;
    }else if(maxp < maxq){
      r[i] = (power(2ll, maxq) + power(2ll, p[i - maxqind]))%mod;
    }else{ // if maxp == maxq
      if(p[i-maxqind] > q[i-maxpind]){
        r[i] = (power(2ll, maxq) + power(2ll, p[i - maxqind]))%mod;
      }else{
        r[i] = (power(2ll, maxp) + power(2ll, q[i - maxpind]))%mod;
      }
    }
  }
  for(int i = 0; i< n; i++)
  {
   cout << r[i] << " ";
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