/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int modPow(int base, int exp) {
  int res = 1;
  while (exp > 0) {
      if (exp & 1ll) res = (res * base) % MOD;
      base = (base * base) % MOD;
      exp >>= 1ll;
  }
  return res;
}

int modinv(int a) {
    return modPow(a, MOD - 2);
}

void Solve(){
    int n,m; cin>>n>>m;
    map<int,int> mp;
    for(int i =0;i <n; i++){
        int x; cin>>x; mp[x]++;
    }

    vector<pair<int,int>> a(mp.size());
    int i  =0;
    for(auto p : mp){
        a[i++] = p;
    }
    if(a.size() < m){
        cout <<"0"<<endl;
        return;
    }

    int ans =0;
    int prod = 1;
    for(int r=0; r < m; r++){
        prod *= a[r].second;
        prod %= MOD;
    } // r = m, l = 0
    if(a[m-1].first- a[0].first+1==m)ans = (ans+prod)%MOD;

    for(int i = m;i < a.size(); i++){
        prod *= a[i].second;
        prod %= MOD;
        prod *= modinv(a[i-m].second);
        prod %= MOD;
        if(a[i].first- a[i-m+1].first+1 ==m)ans= (ans+prod)%MOD;
    }
    cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
