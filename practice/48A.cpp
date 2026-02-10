/**
 *    author: Anicetus_7
 *    created: 2025-12-22 09:37:26
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define F cout<<"F\n"
#define S cout<<"S\n"
#define M cout<<"M\n"

void Solve(){
  string f, m, s; cin>>f>>m>>s;
  int nf, nm, ns; 
  if(f=="rock" && s == "scissors" && m =="scissors")F;
  else if(f=="rock" && s == "paper" && m =="rock")S;
  else if(f=="rock" && s == "rock" && m =="paper")M;
  else if(f=="scissors" && s == "paper" && m =="paper")F;
  else if(f=="scissors" && s == "rock" && m =="scissors")S;
  else if(f=="scissors" && s == "scissors" && m =="rock")M;
  else if(f=="paper" && s == "rock" && m =="rock")F;
  else if(f=="paper" && s == "scissors" && m =="paper")S;
  else if(f=="paper" && s == "paper" && m =="scissors")M;
  else cout << "?\n";
  
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