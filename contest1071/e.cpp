/**
 *    author: Anicetus_7
 *    created: 2025-12-24 14:16:35
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,x,y; cin>>n>>x>>y;
  string s; cin>>s;
  vector<int> p(n);
  for(int i =0 ;i < n; i++)cin>>p[i];
  
  int n1 = 0, n2 = 0;
  int sum1= 0 , sum2 = 0;
  for(int i =0;i < n; i++){
    if(s[i] =='0'){
      n1++;
      sum1 += p[i]/2 + 1;
    }else{
      n2++;
      sum2 += p[i]/2 + 1;
    }
  }
  if(x+ y < accumulate(p.begin(), p.end(), 0ll)){
    cout << "No\n";
    return;
  }
  if(x < sum1 || y < sum2){
    cout << "No\n";
    return;
  }
  if(n1 == n || n2 == n){
    if(n1== n && x-y < n){
      cout << "No\n";
    }else if(n2== n && y-x < n){
      cout << "No\n";
    }else{
      cout << "Yes\n";
    }
  }else cout << "Yes\n";
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