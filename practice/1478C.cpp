/**
 *    author: Anicetus_7
 *    created: 2026-01-13 16:31:04
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
  int n; cin >> n;
  vector<int> a(2 * n);
  map<int, int> mp;
  
  for(auto& x : a) {
    cin >> x;
    mp[x]++;
  }

  if(mp.size() != n) {
    cout << "NO\n"; return;
  }

  vector<int> d; // To store unique sums
  for(auto& [val, count] : mp){
    if(count != 2 || val % 2 != 0){
      cout << "NO\n"; return;
    }
    d.push_back(val);
  }
  
  // 2. Process from largest sum to smallest
  // Map keys are already sorted, but let's be explicit with the vector
  sort(d.begin(), d.end()); 
  
  int subtract_sum = 0; // The sum of 2*a[j] for all j > i processed so far
  
  for(int i = n - 1; i >= 0; i--){
    int val = d[i];
    
    // Formula derivation: 
    // val = 2 * (i + 1) * current_a + subtract_sum
    // So: current_a = (val - subtract_sum) / (2 * (i + 1))
    
    val -= subtract_sum;
    int count_coeff = 2 * (i + 1);

    if(val <= 0 || val % count_coeff != 0){
      cout << "NO\n"; return;
    }
    
    int current_a = val / count_coeff;
    subtract_sum += 2 * current_a;
  }

  cout << "YES\n";
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