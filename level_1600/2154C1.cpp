/**
 *    author: Anicetus_7
 *    created: 2025-10-19 21:23:57
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200000)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#undef int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Value>
using umap = gp_hash_table<Key, Value>;
#define int long long

vector<vector<int>>  p(MAX+1); // stores the prime divisors of i
void generate(){
  for(int i = 2; i <=MAX; i++){
    if(!p[i].empty())continue;// if i is not prime
    for(int j = i; j <= MAX; j+=i)p[j].push_back(i); // push the divisor i 
  }
}

void Solve(){
  int n;cin>>n;
  vector<int> a(n);for(auto& x : a)cin>> x;
  vector<int> b(n);for(auto& x : b)cin>> x;

  umap<int,int> mp;
  for(int i = 0; i< n; i++)
  {
    for(int x: p[a[i]]){
      mp[x]++;
      if(mp[x] >1 ){
        cout << 0 << endl;
        return;
      }
    }
  }

  // for getting 1, we need to check whether 
  // on adding 1 to anybody
  // it starts sharing divisors with other numbers
  for(int i = 0 ; i < n; i++){
    for(int x : p[a[i]])mp[x]--;
    for(int x :p[a[i]+1]){
     if(++mp[x] > 1){
      cout<< 1 << endl;
      return;
     }
    }
    for(int x :p[a[i]+1])mp[x]--;
    for(int x: p[a[i]])mp[x]++;
  }
  
  // general case for 
  // all odd numbers
  cout << 2 << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  generate();
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