/**
 *    author: Anicetus_7
 *    created: 2025-07-02 17:14:39
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

void Solve(){
  int n,k ; cin>> n>>k;
  vector<int> efficiency(n);for(int& x : efficiency)cin>>x;
  vector<int> prefix(n);
  prefix[0] = 0;
  for(int i = 0; i < n-1; i++){
    prefix[i+1] = prefix[i] + abs(efficiency[i]- efficiency[i+1]);
  }
  int mxsum  = 0;
  cout << prefix[n-1] << endl;
  for(int i= 0 ;i < n-k; i++){
    int deduction = prefix[i+k]- prefix[i];
    int newpair  = 0;
    if(i > 0)newpair = abs(efficiency[i-1] - efficiency[i+k]);
    mxsum = max(mxsum, newpair-deduction+prefix[n-1]);
  }
  cout << mxsum << endl;
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i = 1; i <= t; i++) 
    {
        cout << "Case #" << i << ": ";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now(); 
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  return 0;
}


void Solve2() {

    int n,k ; cin>> n>>k;
    vector<int> efficiency(n);for(int& x : efficiency)cin>>x;

    if (n <= 1){
      cout << 0 << endl;
    }

    vector<int> diff(n - 1), prefix(n);
    for (int i = 0; i < n - 1; ++i)
        diff[i] = abs(efficiency[i] - efficiency[i + 1]);

    for (int i = 0; i < n - 1; ++i)
        prefix[i + 1] = prefix[i] + diff[i];

    int total = prefix[n - 1];
    int ans = 1e18;

    for (int i = 0; i + k <= n; ++i) {
        int removed = prefix[i + k - 1] - prefix[i];

        int border_loss = 0, border_gain = 0;
        if (i > 0) border_loss += diff[i - 1];
        if (i + k < n) border_loss += diff[i + k - 1];
        if (i > 0 && i + k < n)border_gain = abs(efficiency[i - 1] - efficiency[i + k]);

        int new_total = total - removed - border_loss + border_gain;
        ans = min(ans, new_total);
    }

    cout <<  ans <<endl;
}

