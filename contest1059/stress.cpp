/**
 *    author: Anicetus_7
 *    created: 2025-10-22 11:42:42
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> cur;
void find(int len, int n){
  if(len == n){
    cout << len << " " << len << endl;
    for(int x: cur){
      cout << x << " ";
    }
    cout << endl;
    return;
  }
  for(int i =1; i <= n ; i++){
    cur.push_back(i);
    find(len+1, n);
    cur.pop_back();
  }
}

void Solve(){
  int n= 5;
  for(int i =3; i <=n; i++){
    find(0, i);
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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