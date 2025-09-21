/**
 *    author: Anicetus_7
 *    created: 2025-09-20 21:04:52
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;

  if(n == 1){
    cout << "1 1" << endl;
    return;
  }

  for(int i = n- (n%2==0); i >=3; i-=2){
    cout << i << " ";
  } 
  if(n&1){
    cout << 1 << " " << n-1 <<" ";
  }else cout << n << " " << 1 << " ";

  for(int i = 3; i <=n- (n%2==0); i+=2){
    cout << i << " ";
  } 

  for(int i = n- (n%2)-2; i >=2; i-=2){
    cout << i << " ";
  } 
  cout << n - (n&1) << " ";
  for(int i = 2; i <=n- (n%2)-2; i+=2){
    cout << i << " ";
  } 
  cout <<"1\n";
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