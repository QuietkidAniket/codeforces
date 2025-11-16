/**
 *    author: Anicetus_7
 *    created: 2025-11-03 03:19:05
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

bitset<MAX> dp;
int a[101];

int check(int n){
  int res= 0;
  while(n%2==0){
    res++;
    n >>=1;
  }
  return res;
}
void Solve(){
  int n; cin>>n;
  for(int i = 0; i <n ; i++)cin>> a[i];
  int sum = 0;
  dp[0] = 1;
  for(int i =0 ;i <n ;i++){
    dp |= (dp<<a[i]);
    sum += a[i];
  }  
  
  if((sum &1) || !dp[sum/2]){
    cout << "0 \n";
    return;
  }

  int elem= 0;
  int mn = check(a[0]);
  for(int i = 1;i < n; i++){
    int res = check(a[i]);
    if(res < mn){
      mn = res;
      elem = i;
    }
  }

  cout << "1 \n" << elem +1 << endl; 
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