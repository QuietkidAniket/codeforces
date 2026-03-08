/**
 *    author: Anicetus_7
 *    created: 2026-01-14 12:57:02
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


int C(int n, int k) {
	if (k > n - k) { k = n - k; }
	int ret = 1;
	for (int i = 0; i < k; i++) {
		// this is done instead of *= for divisibility issues
		ret = ret * (n - i) / (i + 1);
	}
	return ret;
}

void Solve(){
  int n; cin>>n;
  int k; cin>>k;
  cout << C(n-1,k-1) << endl;
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