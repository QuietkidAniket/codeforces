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

vector<int> divs[MAX];

void Solve(){
	int n; cin>>n;
	int a[n];
	int freq[MAX] = {0};
	int mx =0;
	for(int i = 0; i< n; i++)
	{
	    cin>>a[i];
		for(int div: divs[a[i]])freq[div]++;
		mx = max(a[i], mx);
	}

	int ans =1;
	for(int i = 2; i <=mx ; i++){
	    if(freq[i] >= n-1)ans = (ans*i)/gcd(ans, i);
	}
	cout << ans << endl;
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  cin>> t;
  for(int i=2;i < MAX; i++){
    for(int j = i; j<MAX; j+=i)divs[j].push_back(i);
  }
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
