#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;

void Solve(){
 // Problem is sum of subarrays 
    
    // int n; cin >> n;
    int n = 1 + RNG() % 5;
    
    vector <int> a(n + 1);
    
    for (int i = 1; i <= n; i++){
        // cin >> a[i];
        a[i] = 1 + RNG() % 5;
    }
    
    auto brute = [&](){
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int sum = 0;
            for (int j = i; j <= n; j++){
                sum += a[j];
                ans += sum;
            }
        }
        
        return ans;
    };  
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += a[i] * (i) * (n + 1 - i);
    }
    
    int brute_ans = brute();
    
    if (brute_ans != ans){
        cout << n << "\n";
        for (int i = 1; i <= n; i++){
            cout << a[i] << " \n"[i == n];
        }
        cout << brute_ans << " " << ans << "\n";
        exit(0);
    }
    
    // cout << ans << "\n";
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}