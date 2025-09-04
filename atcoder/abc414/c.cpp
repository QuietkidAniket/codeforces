/**
 *    author: Anicetus_7
 *    created: 2025-07-12 17:56:43
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


string converta(int num, int a){
  string res = "";
  while(num > 0){
    int temp = num%a;
    if(temp >= 9){
      res.push_back((char)('a'+ (temp - 10)));
    }else res.push_back((char)'0'+temp);
    num /= a;
  }
  reverse(res.begin(), res.end());
  return res;
}


bool check(int num, int a){
  string res = converta(num, a);
  int l = 0, r = res.size()-1;
  while(l <= r){
    if(res[l] != res[r]){
      return false;
    }
    l++,r--;
  }
  return true;
}


static vector<int> pal;

static const int generate = [](){
  for(int i = 0; i <= 1e6;i++){
    int n_digits = (log10(i) +1 );
    int p = pow(10, n_digits);
    if()
    if()
  }
  return 0;
}();


void Solve(){
  int n, a; cin>>a>>n;

  
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