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
    int x, y; cin>>x>>y;
    int a = 0, b=0;
    if(y < 0){
        a += abs(y)*4;
        if(a > x || (x-a)%3 != 0){
            cout << "No\n";
        }else cout << "Yes\n";
    }else if(y > 0){
        a += abs(y)*2;
        if(a > x || (x-a)%3 != 0){
            cout << "No\n";
        }else cout << "Yes\n";
    }else{
        if(a > x || (x-a)%3 != 0){
            cout << "No\n";
        }else cout << "Yes\n";
    }

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
