/**
 *    author: Anicetus_7
 *    created: 2025-07-21 18:39:34
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


int manhattan(pii& a, pii& b){
  auto [x1,y1] = a;
  auto [x2,y2] = b;
  return abs(x1-x2) + abs(y1-y2);
}
void Solve(){
  int n; cin>>n;
  vector<pair<pii,int>> a(n);
  for(int i = 0; i< n; i++)
  {
    int x, y;cin>> x>>y;
    a[i] = {{x,y}, i+1};
  }
  
  sort(a.begin(), a.end());
  auto cmp = [](pair<pii,int>&a, pair<pii, int>&b){return a.first.second < b.first.second;};

  sort(a.begin(), a.begin()+n/2, cmp);
  sort(a.begin()+n/2 , a.end(), cmp);

  for(int i =0; i <n/2; i++){
    cout << a[i].second << " " << a[n-i-1].second << endl;
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
        //cerr << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}