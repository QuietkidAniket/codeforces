/**
 *    author: Anicetus_7
 *    created: 2025-12-19 20:51:26
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

/*
first try to unset all the set bits in n atleast once
then try to compensate for those bits by setting the unset bits after it but even times
*/

void Solve(){
  int n, k;
  cin >> n >> k;
  vector<int> a(k, n);
  if(k%2==0){
    int ptr = 0;
    for(int pos = 29; pos >= 0 ; pos--){
      if(n&(1<<pos)){ 
        // unset the bit (and this happens only k times to make the number of unset bits in different numbers as even as k is even)
        if(ptr < k){
          a[ptr] ^= (1<<pos);
          ptr++;
        }else{ 
          // in case of k < no. of set bits in n...
          // then the remaining lower order bits are unset just once in one number in the list (to make the count odd)
          a[0] ^= (1<<pos);
        }
      }else{
        // set even number of bits in that position pos if its unset in n
        // these numbers are anyways <= n as their higher order bits have been unset
        // this doesnt interfere with any set bits 
        for(int i =0 ;i +1< ptr; i+=2){
          a[i] ^= 1<<pos;
          a[i+1] ^= 1<<pos;
        }
      }
    }
  }
  for(auto& x: a)cout << x << " ";
  cout <<endl;
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