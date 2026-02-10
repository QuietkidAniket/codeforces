/**
 *    author: Anicetus_7
 *    created: 2025-12-08 18:48:32
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n, target; cin>>n>>target;  
  vector<pair<int,int>> a(n);
  for(int i = 0; i <n; i++){
    cin>>a[i].first;
    a[i].second = i+1;
  }

  sort(a.begin(), a.end());
  for(int i= 0;i < n-1; i++){
    int t = target- a[i].first;
    int l = i+1, h = n-1;
    while(l < h){
      int sum = a[l].first  + a[h].first;
      if(sum > t){
        h--;
      }else if(sum < t){
        l++;
      }else{
        cout << a[i].second <<" " << a[l].second <<" "<< a[h].second << endl;
        return;
      }
    }
  }
  cout << endl;


  cout << "IMPOSSIBLE" << endl;
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