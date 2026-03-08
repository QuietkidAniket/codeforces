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
	int n;cin>>n;
	vector<int> p(n+1);
	if(n&1){
    	iota(p.begin(), p.end(), 0);
    	for(int i = 2;i < n; i+=2){
    	    swap(p[i], p[i+1]);
    	}
    	swap(p[1], p[n]);
    	for(int i =1; i <= n; i++)cout << p[i] <<" ";
    	cout << endl;
	}else{
	    if((n&(n-1)) == 0){
			cout << -1 <<endl;
			return;
		}
    	iota(p.begin(), p.end(), 0);
	    int bit = 1ll<<(63 -__builtin_clzll(n));
    	for(int i = 2;i < n; i+=2){
    	    swap(p[i], p[i+1]);
    	}
    	swap(p[1], p[n]);
        int firstbit = 1;
        while(firstbit < bit && (n&firstbit)==0)firstbit<<=1;
        // int idx = n^firstbit;
        swap(p[firstbit], p[1]);
		for(int i =1; i<= n; i++)cout << p[i] <<" ";
		cout<<endl;
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
        //cout << "Case #" << i << ": \n";
        Solve();
    }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}
