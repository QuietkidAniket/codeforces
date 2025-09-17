/**
 *    author: Anicetus_7
 *    created: 2025-09-13 21:02:50
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

  vector<vector<int>> a(n);

  int mx = 0;
  for(int i = 0; i< n; i++)
  {
   int k ; cin>>k;
   vector<int> t(k);
   for(auto& x : t)cin>> x;
   mx = max(mx, (int)t.size());
   a[i] = t;
  }

  sort(a.begin(), a.end());

  vector<int> ans(mx);
  for(int i = 0 ; i <a[0].size(); i++){
    ans[i] = a[0][i];
  }
  
  int z=a[0].size();

  while(z< mx){
    sort(a.begin(), a.end(), [z](const vector<int>& v1, const vector<int>& v2) {
      if(v1.size() <= z)return false;
      if(v2.size() <= z)return true;
      int n1 = v1.size(), n2 = v2.size();
      int i = z;
      while(i < n1 && i < n2) {
        if(v1[i] != v2[i]) return v1[i] < v2[i];
        i++;
      }
      return n1 < n2;
    });
    
    for(int i = z; i <a[0].size(); i++){
      ans[i] = a[0][i];
    }
    z= a[0].size();
  }
  
  
  for(auto x: ans){
    cout << x << " ";
  }
  cout <<endl;
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