/**
 *    author: Anicetus_7
 *    created: 2025-07-05 17:56:02
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin>>n;
  vector<int> arr(n); for(auto& x : arr)cin>>x;
  
  // edge case
  if(n == 2){cout << "Yes\n";return;}


  sort(arr.begin(), arr.end(), [](int a, int b){
    return abs(a) < abs(b);
  });
  bool flag = false;
  for(int i = 2; i <n; i++){
    if(arr[i] * arr[i-2] != arr[i-1] * arr[i-1]){
      flag = true;
      break;
    }
  }


  if(!flag)cout << "Yes\n";
  else{ 
    map<int,int> mp;
    for(int i = 0; i< n; i++)
    {
     mp[arr[i]]++;
    }
    if(mp.size() ==2){
      if(mp.begin()->first == -1 * (mp.rbegin()->first) && abs(mp.begin()->second - mp.rbegin()->second ) <= 1){
        cout << "Yes\n";
      }else{
        cout << "No\n";
      }

    }else{
      cout << "No\n";
    }
  }
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