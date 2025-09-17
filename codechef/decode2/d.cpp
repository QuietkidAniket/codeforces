// _______ Author : Anicetus_7 ____________
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(2*1e5)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
 int n; cin>>n;
 vector<int> a(n);
 for(auto& x : a)cin>>x;
 int x; cin>>x;
 int ans = 0ll;
 for(int i =0; i <n; i++){
    int low =i+1, high = n-1, res = i;
    // while(low <= high){
    //     int mid  = (low+high)>>1;
    //     if(a[mid] +a[i]< x){
    //         res = mid;
    //         low = mid + 1;
    //     }else high = mid -1;
    // }
    res = upper_bound(a.begin()+i, a.end(), x -a[i]) - a.begin() - 1;
    ans += res-i;
 }
 cout <<ans <<endl;
}


//_______________[MAIN]__________________
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
//   cin>> t;
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
