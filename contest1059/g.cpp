/**
 *    author: Anicetus_7
 *    created: 2025-10-22 18:28:51
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
  if(n == 2){
    cout << "-1\n";
  }else if(n == 3){
    cout << "3 1\n3 2\n";
  }else if(n == 4){
    cout << "1 2\n1 4\n1 3\n";
  }else if(n >=5){
    cout << "1 2\n2 3\n3 4\n";
    for(int i =5; i <= n-1; i++)cout << "2 " << i <<"\n";
    cout << "1 " << n << "\n";
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