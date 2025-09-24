/**
 *    author: Anicetus_7
 *    created: 2025-09-22 21:10:34
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());

//  auto check= [&](int target){
//     int hand = 0, rem = target;
//     for(int i = 0; i < n; i++){
//         if(rem <= 0) break;
//         if(a[i] - a[i+1] > 0){
//             if(rem < (a[i] - a[i+1]) * (i + 1)){
//                 hand += rem;
//                 break;
//             }
//             hand += (i + 1) * (a[i] - a[i+1]);
//             rem -= (i + 1) * (a[i] - a[i+1]);
//         }
//         if(i + 1 < n && rem > 0) rem--;
//     }
//     return hand >= k;
// };
            
    // lambda khud se use kiya hu, flag maat karna Parth
    a.push_back(0);
    auto check = [&](int target){
      int hand = 0, rem = target;
      for(int i =n ; i >0 ; i--){
        if(rem <= 0)break;
        if(a[i-1] - a[i] > 0){
          if(rem < (a[i-1] - a[i])*i){ 
            hand += rem;
            break;
          }
          hand +=i*(a[i-1]-a[i]); 
          rem -= i*(a[i-1]-a[i]);
        }
        if(i > 1 && rem > 0)rem--;
      }
      return hand >= k;
    };

    int low = 1, high = 1e12, ans = -1;
    while (low <= high) {
        int mid = (low + high)>>1;
        if (check(mid) ){
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    cout << ans << endl;
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