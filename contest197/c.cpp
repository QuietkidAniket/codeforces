/**
 *    author: Anicetus_7
 *    created: 2025-07-30 20:10:29
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  // if(n <= 4){
  //   cout << ;
  //   vector<int> a(n);
  //   for(int i = 0; i< n; i++)a[i] = i+1;
  //   do{
  //     for(auto& x : a)cout<<x;
  //     cout << endl;
  //   }
  //   while(next_permutation(a.begin(), a.end()));
  // }else{
    vector<int> a(n);
    cout << 2 << endl;
    for(int i = 0; i< n; i++)
    {
     a[i ] = i+1; 
     cout << a[i] << " ";
    }
    cout << endl;
    for(int i = n-1; i>=0; i--)
    {
      cout << a[i] << " ";
    }
    cout << endl;

  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}