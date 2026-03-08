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
    vector<int> a(n+1);
    vector<int> inv(n+1,0);
    for(int i = 1; i <= n; i++){cin>> a[i];inv[a[i]] = i;}
    bool flag = true;
    for(int i = 1;i <= n; i++){
        if(i != a[i]){
            int idx = inv[i];
            if(idx > i){
                int res = idx/i;
                if(idx%i == 0 &&  ((res)&(res-1)) ==0)flag= true;
                else{ flag = false;break;}
            }else{
                int res = i/idx;
                if(i%idx == 0 && ((res)&(res-1)) ==0)flag= true;
                else{ flag = false;break;}
            }
        }
    }
    
    if(flag)cout << "YES\n";
    else cout << "NO\n";
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
