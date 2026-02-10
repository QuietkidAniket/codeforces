/**
 *    author: Anicetus_7
 *    created: 2025-11-30 12:35:39
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n,k; cin>>n>>k;
  vector<int> q(n), r(n);
  for(int i =0 ;i < n; i++){
    cin>>q[i] ;
  }

  for(int i =0 ;i < n; i++){
    cin>>r[i] ;
  }

  sort(r.begin(), r.end());
  sort(q.begin(), q.end());

  auto check = [&](int ptr){
    for(int i =0 ;i < n && ptr >=0; i++){
      int res= q[ptr--] * (r[i] + 1) + r[i];
      if(res > k)return false;
    }
    return true;
  };

  int l = 0, h = n-1, ans =-1;
  while(l <= h){
    int mid =(l+h)>>1;
    if(check(mid)){
      l = mid +1;
      ans = mid;
    }else{
      h = mid-1;
    }
  }
  cout <<ans +1<<endl;
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