/**
 *    author: Anicetus_7
 *    created: 2025-09-02 01:05:29
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int mx[2];
  int k; cin>>mx[0]>>mx[1]>>k;

  if(abs(mx[0]-mx[1]) > k){
    cout << -1 << endl;
    return;
  }

  int c =1;
  if(mx[0] > mx[1]){
    c= 0;
  }
  string res;

  for(int i = 0; i< k; i++)
  {
    res += (c==0? "0" : "1");
    mx[c]--;
  }
  while(mx[0]>0 && mx[1]>0){
    res += (c==1? "01":"10");
    mx[0]--;
    mx[1]--;
  }
  
  if(mx[c]!=0){
    cout << -1 << endl;
    return;
  }
  while(mx[1-c]>0){
    res+= ((1-c)  ==0? "0" : "1");
    mx[1-c]--;
  }
  cout <<res << endl;
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