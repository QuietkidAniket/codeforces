/**
 *    author: Anicetus_7
 *    created: 2025-07-30 20:17:28
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    auto count = [&](int target){
        int divs = 0, cur = 0, mx =0;
        for(int i = 0; i< n; i++)
        {
            if(s[i] == '0'){
                cur++;
                mx = max(mx, cur);
            }else{
                mx++;
            }
            if(mx >= target){
                cur = 0;
                mx = 0;
                divs++;
            }
        }
        return divs;    
    };

    int l = 1, r = n, ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        int parts = count(mid);

        if (parts >= k) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}