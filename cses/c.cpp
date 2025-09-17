/**
 *    author: Anicetus_7
 *    created: 2025-09-10 23:22:41
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;

  vector<int> a(n);

  for(auto& x : a)cin>>x;
  
  vector<pair<int,int>> e1,e2,o1,o2;
  int esum =0 , osum = 0;

  // cout << "hehe\n";
  for(int i =0; i < n; i++){
    if(i &1){
      o1.push_back({2*a[i] + i, i}); 
      o2.push_back({2*a[i] - i, i});
       osum += a[i];}
    else{ 
      e1.push_back({2*a[i] + i,i}); 
      e2.push_back({2*a[i] - i,i}); 
      esum+=a[i];
    }
  }

  sort(o1.rbegin(), o1.rend());
  sort(o2.rbegin(), o2.rend());
  sort(e1.begin(), e1.end());
  sort(e2.begin(), e2.end());

  int res = esum - osum;
  int r = res;
  if(o1.size() >0 && e1.size()>0){
    r = max(r, o1[0].first -e1[0].first + res);
  }
  if(o2.size() >0 && e2.size()>0){
    r = max(r, o2[0].first -e2[0].first + res);
  }
  int t = 0;
  if(n &1){
    t = res  +  n-1;
  }else{
    t = res + n-2;
  } 
  cout << max(r, t) << endl;
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