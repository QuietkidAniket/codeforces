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

map<int, int> mp;

void Solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto& x: a)cin>> x;

    int ans = 0;
    int prev = a[0];
    for(int i=1;i<n;i++){
        if(mp[prev] == a[i] || prev == a[i]){
            ans++;
            prev = -1;
        }
        else{
            prev = a[i];
        }
    }
    cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
    mp[1] = 6;
    mp[6] = 1;
    mp[5] = 2;
    mp[2] = 5;
    mp[3] = 4;
    mp[4] = 3;
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
