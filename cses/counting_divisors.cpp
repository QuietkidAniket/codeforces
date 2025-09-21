/**
 *    author: Anicetus_7
 *    created: 2025-09-21 14:16:38
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(1e6+ 1)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


static int numdivisors[MAX]; 
static bool flag = false;

void pre(){
  if(flag)return;
  for(int i =1; i < MAX; i++){
    for(int j = i; j < MAX; j+=i){
      numdivisors[j]++;
    }
  }
  flag = true;
}

void Solve(){
  int n; cin>>n;
  cout <<numdivisors[n]<<endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  pre();
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