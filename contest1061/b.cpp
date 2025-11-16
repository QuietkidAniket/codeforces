/**
 *    author: Anicetus_7
 *    created: 2025-10-25 09:24:09
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,q; cin>>n>>q;
  string s; cin>>s;
  bool g = false;
  for(char c : s){
    if(c == 'B')g |= true;
  }
  for(int i =0; i <q; i++){
    int num; cin>>num;
    if(!g){
      cout << num << endl;
      continue;
    }
    int cnt =0;
    while(num > 0){
      int t = num;
      int j;
      for(j = 1; j <= n; j++){
        if(s[j-1] == 'A'){
          t--;
        }else{
          t>>=1;
        }
        if(t == 0)break;
      }
      if(t == 0){
        cout << cnt + j <<endl;
        break;
      }else{
        num = t;
        cnt += n;
      }
    }
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