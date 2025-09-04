/**
 *    author: Anicetus_7
 *    created: 2025-07-22 20:53:46
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  for(int i = 1; i <MAX; i++){
    for(int j = 1; j< n; j++)
    {
      for(int k = 1; k< n; k++){
        
        int res =0;




        int ans =0;
        if(k >=a && k >= b)ans = 1;
        else if(a == b){
          if(k >a)ans = 1;
          else{
            
          }
        }else{ 
          bool flag = false;
          for(int i =2ll; i <= min(a,b); i++){
            if(a%i == 0 && b%i == 0 && (i%k == 0 || i <=k)){
              ans = 1;
              flag = true;
              break;
            }
          }
          if(!false)ans = 2;
        }
        if(res != ans){
          cout << i << " "<< j  <<  " " <<  k << endl;
        }
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
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}