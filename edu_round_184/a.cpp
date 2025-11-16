/**
 *    author: Anicetus_7
 *    created: 2025-11-15 09:40:30
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, alice; cin>>n>>alice;

  int a[n]; 
  for(int i = 0 ;i <n ;i++)cin>>a[i];
  int cnt1 =0; // marbles less than alice
  int cnt2 =0; // marbles more than alice
  for(int i = 0;i < n; i++){
    if(alice > a[i])cnt1++;
    else if(alice < a[i])cnt2++;
  }
  if(cnt1 <= cnt2){
    cout << alice +1 << endl;
  }else cout << alice -1 << endl;
  
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