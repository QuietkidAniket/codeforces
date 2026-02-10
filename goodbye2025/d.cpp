/**
 * author: Anicetus_7
 * created: 2025-12-27 22:42:05
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define val first
#define id second

void Solve(){
  int n, m; cin>>n>>m;
  vector<pair<int,int>> a(n); 
  int sum = 0ll;
  for(int i =0 ;i < n; i++){cin>>a[i].val; a[i].id= i+1; sum += a[i].val;}

  sort(a.begin(), a.end());

  if(n/2 < m){
    cout << -1 << endl;
    return ;
  }
  if(m == 0){
    sum -= a[n-1].val;
    if(sum < a[n-1].val){
      cout << -1 << endl;
      return ;
    }
    sum = a[n-1].val;
    // greedily choose those who can remove 
    int idx =n-2; // the slayer element... who is going to give the final blow to the last element
    while(idx >= 0){
      sum -= a[idx].val;
      if(sum <= 0)break;
      idx--;
    }
    cout << (n-1) <<  endl;
    for(int i = 0 ;i < idx; i++){
      cout << a[i].id << " " <<  a[i+1].id << endl;
    }
    for(int i = n-2; i >= idx; i--){
      cout << a[i].id << " " <<  a[n-1].id << endl;
    }
  }else{
    cout << n-m << endl;
    for(int i =m;i < n; i++){
      cout << a[i].id << " " << a[i-m].id <<endl;
    }
  }
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin >> t; 
  for(int i = 1; i <= t; i++) 
  {
    // cout << "Case #" << i << ": \n";
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}