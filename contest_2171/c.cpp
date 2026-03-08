/**
 *    author: Anicetus_7
 *    created: 2026-01-12 17:06:34
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
  vector<int> a(n);
  for(auto& x : a)cin>> x;
  vector<int> b(n);
  for(auto& x : b)cin>> x;
  if(b ==a ){
    cout << "Tie\n";
    return;
  }
  int cnt1 =0, cnt2 =0;
  int id1 =-1, id2 =-1;
  for(int i =0 ; i <n; i+=2){
    if(a[i] ^ b[i]){
      cnt1++;
      id1 = i;
    }
  }
  for(int i = 1; i < n; i+=2){
    if(a[i] ^ b[i]){
      cnt2++;
      id2 =i;
    }
  }
  if((cnt1+cnt2)%2 == 0) cout << "Tie\n";
  else if(id1 < id2)cout << "Mai\n";
  else if(id1 > id2 ) cout << "Ajisai\n";
  return ;
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