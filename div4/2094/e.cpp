/**
 *    author: Anicetus_7
 *    created: 2025-09-20 09:36:29
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
  vector<int> a(n); for(auto& x : a)cin>> x;

  int freq[31] = {0};

  for(int i = 0 ; i <n; i++){
    int x = a[i];
    for(int j = 0; j < 31; j++){
      if(x & (1<<j))freq[j]++; 
    }
  }
  int mx = 0;
  for(int i = 0 ; i <n; i++){
    int x= a[i];
    int sum =0;
    for(int j = 0; j < 31; j++){
      // if set in x, it unsets and hence not added to sum,
      // but instead rest unset bits are set and added
      if(x  & (1 << j))sum += (1<<j)*(n-freq[j]);
      // if not set in x, already set bits are added to sum
      else sum += (1<<j)*(freq[j]);
    }
    if(mx < sum){
      mx = sum;
    }
  }
  cout << mx << endl;
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