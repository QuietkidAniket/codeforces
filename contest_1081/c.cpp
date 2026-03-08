/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
	int n,h,k; cin>>n>>h>>k;
	vector<int> a(n); for(auto& x : a)cin>> x;
	vector<int> pref(n+1, 0), pm(n+1, INF), sm(n+1, 0);
	for(int i = 0 ; i < n ; i++){
	    pref[i+1]=  pref[i] +  a[i];
		pm[i+1] = min(pm[i], a[i]);
	}
	for(int i = n-1 ; i >= 0; i--)sm[i] = max(sm[i+1], a[i]);
	
	int c= (h-1)/pref[n];
	int rem = h - c*pref[n];
	
	// if(rem == 0){
	//     cout << c*(n+k) - k << endl;
	// 	return;
	// }
	int sum  = 0, i;
	for(i = 1;i <= n ; i++){
	    int cur  = pref[i];
	    if(i < n){
			cur += max(0ll, sm[i] - pm[i]);
		}
		if(rem - cur <= 0){
		    break;
		}
	}
	cout << c*(n+k)+ i<< endl;

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
