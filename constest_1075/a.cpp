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
	int n,h,l; cin>>n>>h>>l;
	vector<int> a(n); for(auto& x : a)cin>> x;

	auto check1 = [&](int x){
	    return x <= h && x>= 1;
	};
	auto check2 = [&](int y){
	    return y<=l && y>=1;
	};
	int r =0, c =0, com= 0;
	for(int i =0; i < n; i++){
	    if(check1(a[i]) && check2(a[i]))com++;
	    else if(check1(a[i]))r++;
		else if(check2(a[i]))c++;
	}
	
	int ans = min(r, c);
	int rem = r+c - ans;
	ans += min(rem, com);
	com -= min(rem, com);
	ans += com/2;
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
