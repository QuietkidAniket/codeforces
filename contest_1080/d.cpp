/**
 * author: Anicetus_7
 * created: 2026-02-15 21:28:11
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n; cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    
    vector<int> l(n);
    
    int sum = (t[n-1] + t[0]) / (n - 1);
    
    l[0] = (sum + (t[1] - t[0])) / 2;
    
    int tot = l[0];
    
    for(int i = 1; i < n-1; i++){
        int res = (sum + t[i+1] - t[i]) / 2 - tot;
        l[i] = res;
        tot += l[i];
    }
    
    l[n-1] = sum - tot;
    
    for(int i = 0; i < n; i++) cout << l[i] << " ";
    cout << "\n";
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