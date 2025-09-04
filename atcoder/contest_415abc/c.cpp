/**
 *    author: Anicetus_7
 *    created: 2025-07-19 17:40:47
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

bool find(int n, const string& s){
    vector<bool> vis(1LL << n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true; 

    while (!q.empty()) {
        int mask = q.front(); q.pop();
        if (mask == (1ll<<n)-1) return true;

        for (int i = 0; i < n; ++i) {
            if (mask & (1LL << i)) continue;
            int newmask = mask | (1LL << i);

            if (s[newmask - 1] == '1') continue; 

            if (!vis[newmask]) {
                vis[newmask] = true;
                q.push(newmask);
            }
        }
    }
    return false;
}

void Solve(){
  int n; cin>>n;
  string s; cin>>s;

  if(find(n, s))cout << "Yes\n";
  else cout << "No\n";
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}