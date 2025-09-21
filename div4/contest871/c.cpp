/**
 *    author: Anicetus_7
 *    created: 2025-09-20 22:44:56
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
  vector<int> a,b,c; // 01, 10, 11
  for(int i = 0; i< n; i++)
  {
    int m; cin>>m;
    int s; cin>>s;
    if( s == 1) a.push_back(m);
    else if( s == 10) b.push_back(m);
    else if( s == 11) c.push_back(m);
  }
  
  int x = INF,y = INF;
  if(a.size())x =  *min_element(a.begin(), a.end());
  if(b.size())y= *min_element(b.begin(), b.end());

  int z = INF;
  if(c.size())z = *min_element(c.begin(), c.end());
  cout << ((min(x+y, z) == INF) ? -1 : min(x+y, z)) << endl;

  
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