/**
 *    author: Anicetus_7
 *    created: 2025-10-21 11:52:34
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int psum[6][MAX+1];

void Solve(){
  int n,m ; cin>>n>>m;
  string s; cin>>s;
  string t = "abc";
  int idx = 0; 
  do{
    psum[idx][0] = 0;
    for(int i =  0; i <n; i++){
      psum[idx][i+1] = psum[idx][i] + (s[i] != t[i%3]);
    }
    idx++;
  }while(next_permutation(t.begin(), t.end()));

  while(m--){ 
    int  l = 0, r = 0;
    cin>>l>>r;
    int mn = MAX+1;
    for(int i = 0; i <6; i++){
      mn =min(mn, psum[i][r] - psum[i][l-1]);
    }
    cout << mn << endl;
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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