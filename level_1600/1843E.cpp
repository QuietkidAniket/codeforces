#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n,m; cin>> n>>m;
    vector<pair<int,int>> a(m);
    for(auto& x : a)cin>>x.f >> x.s;
    int q; cin>>q;
    vector<int> change(q+1);
    for(int i = 1; i<= q; i++)
    {
      cin>>change[i];
    }

    int l = 0, r = q, ans = -1;
    while(l <= r){
      int mid = (l+r)/2;
      vector<int> b(n+1, -1);
      for(int i = 1; i<= mid; i++)
      {
        b[change[i]] = 1;
      }
      vector<int> p(n+1, 0);
      for(int i = 1; i<= n; i++)
      {
        p[i] = p[i-1] + b[i];
      }
      bool good = false;
      for(auto& [x,y]: a){
        if(p[y]- p[x-1] > 0)good = true;
      }
      if(good){
        ans = mid;
        r = mid -1;
      }else{
        l = mid +1;
      }
    }
    cout << ans << endl;
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}