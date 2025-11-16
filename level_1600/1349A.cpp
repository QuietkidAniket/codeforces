/**
 *    author: Anicetus_7
 *    created: 2025-10-23 12:50:12
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#undef int
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename Key, typename Value>
using umap = gp_hash_table<Key, Value>;
#define int long long

vector<int> divs[MAX+1];

void generate(){
  for(int i =2; i <= MAX; i++){
    for(int j =i; j <= MAX; j+=i){
      divs[j].push_back(i);
    }
  }
}
void Solve(){
  int n;cin>>n;
 vector<int> a(n);
 umap<int,int> freq;
 for(int i =0 ;i <n; i++){
  cin>>a[i];
  for(int num : divs[a[i]]){
    freq[num]++;
  }
 }
 int ans =1;
 for(auto& [x, f] : freq){
  if(f == n || f == n-1)ans = (x*ans)/__gcd(x, ans);
 }  
 cout <<ans <<endl;
  
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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