/**
 *    author: Anicetus_7
 *    created: 2025-12-07 15:27:12
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,q; cin>>n>> q;
  int p[n+1];
  vector<int> pmax(n+1, 0);
  for(int i =1;i<= n; i++){
    cin>>p[i];
  }

  for(int i =1;i<= n; i++){
    pmax[i] = max(pmax[i-1], p[i]);
  }
  string s; cin>>s;
  s = "0" + s;
  
  int bad  = 0;
  for(int i = 1;i <= n; i++){
    if(pmax[i] > i && s[i] == 'L' && s[i+1] == 'R')bad++;
  }


  auto update = [&](int i){ // toggles L to R and vice versa
    if(i-1 >= 1 and s[i-1] == 'L' and s[i] == 'R' and pmax[i-1] > i-1)bad--;
    if(i+1 <= n and s[i] == 'L' and s[i+1] == 'R' and pmax[i]> i)bad--;
    s[i] = s[i] ^ 'L' ^ 'R';
    if(i-1 >= 1 and s[i-1] == 'L' and s[i] == 'R' and pmax[i-1]> i-1)bad++;
    if(i+1 <= n and s[i] == 'L' and s[i+1] == 'R' and pmax[i]> i)bad++;
  };

  for(int i = 1; i<= q;i++){
    int idx; cin>>idx;
    update(idx);
    if(bad == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
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