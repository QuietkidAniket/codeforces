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
	int n; cin>>n;
	vector<int> p(n); for(auto& x : p)cin>> x;
	vector<int> a(n); for(auto& x : a)cin>> x;
	vector<int> vis(n+1,0), inv(n+1,0);
	bool flag = false;
	for(int i =0  ;i < n; ){
	    if(!vis[a[i]]){
			vis[a[i]] = 1;
			int x = a[i];
			while(i < n && a[i]==x)i++;
		}else{
		    flag = true;
			break;
		}
	}
	if(flag){
	    cout <<"NO\n";
	    return;
	}
	for(int i =0 ; i < n; i++){
		inv[p[i]] = i;
	}

	int mn = -INF;
	for(int i =0 ;i < n ;i++){
	    if(inv[a[i]] < mn){		
			flag = true;
			break;
		}
	    mn = max(mn, inv[a[i]]);
	}
	if(flag){
	    cout <<"NO\n";
	}else cout << "YES\n";

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
