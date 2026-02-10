/**
 *    author: Anicetus_7
 *    created: 2025-12-11 20:51:26
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
  int n;
  cin >> n;

  vector<int> a(n), even, odd;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());

  for (int i = 0; i < n; i++){
    if (a[i] & 1) odd.push_back(a[i]);
    else even.push_back(a[i]);
  }
  
  vector<int> pref((int)even.size()+1, 0);
  for(int i = 0; i< even.size(); i++){
    pref[i+1] = pref[i] + even[i];
  }
  for (int k = 1; k <= n; k++){
    // we atleast one odd
    if(odd.empty()){
      cout << 0 << " ";
      continue;
    }
    int neven =  even.size();
    if(neven >= k-1){ // we can fulfill our empty slots with evens
      cout << pref[k-1] + odd[0] << " "; // first k - 1 elements' sum
    }else{ // we need some odd elements to fulfill our empty slots
      int need_odd = k-1 -  neven;
      if(need_odd%2 == 1){ 
        if(neven == 0 || k == n){ 
          cout << 0 << " ";
        }else{ // if its possible to remove one even and add one extra odd...
          int sum =  pref.back() + odd[0];
          sum -= even.back(); 
          cout << sum << " "; 
        }
      }else{ // if there are now even odds
        cout << pref.back() + odd.front() << " "; // first k - 1 elements' sum
      }
    }
  } 

  cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    // cout << "Case #" << i << ": \n";
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}