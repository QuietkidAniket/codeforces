/**
 *    author: Anicetus_7
 *    created: 2025-07-31 20:15:35
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,s; cin>>n>>s;
  int sum =0;
  int freq[3];
  memset(freq,0, sizeof freq);
  vector<int> a(n); for(auto& x : a){cin>>x;freq[x]++; sum += x;}
  if(sum > s){
    for(auto& x : a)cout << x << " ";
    cout << endl;
    return;
  }

  if(sum == s)for(auto& x : a){cout << -1 <<endl;return;}

  if((sum - s) % 3 ==0){cout << -1 << endl;return;}
  int t = sum - 2;
  // if((s-t)%2 == 0){
  //   cout << -1 << endl;
  // }
  if(sum == s-1){
    while(freq[0]--)cout << 0<< " ";
    while(freq[2]--)cout << 2 << " ";
    while(freq[1]--)cout << 1 << " ";
    cout << endl;
  }else{
    cout << -1 << endl;
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
        //cerr << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}