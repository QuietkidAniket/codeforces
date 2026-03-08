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
    int n = (int)1e6;
    vector<int> phi(n+1, 0);
	iota(phi.begin(), phi.end(), 0ll);
	for(int i =2;i <= n;i++){
	    if(phi[i] == i)for(int j= i; j <=n; j+=i)phi[j] -= phi[j]/i;
	}
	vector<int> f(n+1,0);
	// f(n) = sum( div*phi(n/div) ) for all divisors d of n
	for(int i =1;i <= n; i++){ // divisors
	    for(int j = i;j <=n; j+=i){ // the numbers
			if(j%i ==0)f[j] += i*phi[j/i];
		}
	}
	// remove gcd(i,i)
	vector<int> ans(n+1,0);
	for(int i =1;i<=n; i++)ans[i] = ans[i-1] + f[i] - i;

	int N;
	while(cin>>N){
	    if(N == 0)break;
		cout << ans[N] << '\n';
	}
	cout << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // cin>> t;
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
