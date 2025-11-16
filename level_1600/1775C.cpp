/**
 *    author: Anicetus_7
 *    created: 2025-09-28 17:59:28
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,x; cin>>n>>x;
  if(n==x){
    cout << x << endl;
    return;
  }
  if((n&x)!= x){ // cannot set the unset bits in n
    cout << -1 << endl;
    return;
  }

  auto check = [&](int r){
    int a = n, b = r;
    int shift = 0;
    while(a < b){
      a >>=1, b>>=1;
      shift++;
    }
    return (a<<shift);
  };

  int low = n, high = 5*INF;
  while(low <= high){ 
    int mid = (low + high)>>1;
    if(check(mid) <= x){
      high = mid -1;
    }else low = mid + 1;
  }
  if(check(low) !=x)cout << -1<<endl;
  else cout << low <<endl;
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