/**
 *    author: Anicetus_7
 *    created: 2025-06-23 12:26:19
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,q; cin>> n>> q;
  vector<string> p(n);
  string s;

  queue<int> ps;
  queue<pair<int, string>> a;
  queue<int> sp;
  vector<int> query(q);

  int mxind = 0;

  for(int i= 0 ; i< q; i++){
     cin>> query[i];
    int x; string y;
    switch(query[i]){
      case 1 : cin>>x; ps.push(x-1);
      break;
      case 2 : cin>> x >>y; a.push({x-1,y});
      break;  
      case 3 : cin>>x; mxind = i; sp.push(x-1);
      break;
    }
  }
  if((sp.size() == 0) || (a.size() == 0)){
    cout << "" <<endl;
    return;
  }
  for(int i =0; i <= mxind; i++){
    int x; string y;
    switch(query[i]){
      case 1 : x= ps.front(); ps.pop(); p[x] = s;
              break;
      case 2 :x = a.front().first, y = a.front().second; a.pop(); p[x].append(y);
              break;
      case 3 : x = sp.front(); sp.pop(); s = p[x];
              break;
    }
  }
  cout << s << endl;
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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