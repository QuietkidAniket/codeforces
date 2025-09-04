/**
 *    author: Anicetus_7
 *    created: 2025-08-24 09:13:15
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#undef int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Value>
using umap = gp_hash_table<Key, Value>;
#define int long long


umap<int,int> cnt;

int sqrt_(int n){
  int l = 0, h = 5000000001;
  while(l <= h){
    int mid =(l+h)>>1;
    if(mid*mid > n){
      h = mid - 1;
    }else{
      l = mid + 1;
    }
  }
  return l-1;
}

int find(int x, int y){
  int d = x*x - 4*y;
  if(d < 0)return 0;

  int a = (x- sqrt_(d))/2;
  int b = (x + sqrt_(d))/2;
  if(a+ b != x || a*b != y)return 0;

  if(a != b)return cnt[a]* cnt[b];
  else return cnt[a]*(cnt[a]-1)/2;
}

void Solve(){
  int n; cin>>n;
  cnt.clear();
  for(int i = 0; i< n; i++)
  {
   int x; cin>>x;
   cnt[x]++; 
  }
  int _; cin>> _;
  vector<pair<int,int>> q(_); for(auto& [x,y] : q)cin>> x>>y;  

  for(auto [x,y] : q){
    cout << find(x,y)<< " ";
  }
  cout << endl;
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