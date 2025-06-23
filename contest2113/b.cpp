/**
 *    author:  Anicetus_7
 *    created: 2025-06-15 17:09:49
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int w,h, a,b; cin>> w>>h>>a>>b;
  int x1, y1; cin>>x1>>y1;
  int x2,y2; cin>>x2>>y2;
  bool flag = false;
    
    if((abs(x2-x1))%a!=0 && (abs(y2-y1)%b!=0)){
        cout << "No\n";
    }
    else{
        if((x2 -a < x1 && x1<x2+a) && abs(y2-y1)%b!=0){
            cout << "No\n";
        }
        else if((y2-b< y1 && y1< y2+b) && abs(x2-x1)%a!=0){
            cout << "No\n";
        }
        else
        cout << "Yes\n";
    }

  // if(y2 -b < y1 && y1 < y2+b){
  //   if(abs(x2-x1)%a != 0)flag = true;
  // }else if(x2 -a < x1 && x1 < x2+a){
  //   if(abs(y2-y1)%b != 0)flag = true;
  // }else{
  //   if(abs(y2-y1)%b != 0 && abs(x2-x1)%a != 0)flag = true;
  // }
  // if(!flag)cout << "YES"<< '\n';
  // else cout << "NO" << '\n';
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
  cin>> t;
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