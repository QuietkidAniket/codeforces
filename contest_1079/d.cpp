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

void Solve(){
    int n; cin>>n;
    vector<int> a(n+1, 0);
    
    for(int i =1;i<=n;i++)cin>>a[i];
    int cnt=0;
    for(int x=1; x*x <= n; x++){
        for(int j =1; j <=n; j++){
            int i = j - x*a[j];
            if(i<= n &&i>0 && a[i] == x)cnt++;
            if(a[j]*a[j] > n){
                i = j + x*a[j];
                if(i > 0 && i<=n &&a[i] == x)cnt++;
            }
        }
    }
    cout << cnt << endl;
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
