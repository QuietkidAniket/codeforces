/**
 *    author: Anicetus_7
**/
#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
	int n,dist; cin>>n>>dist;
	struct e{int a, b, c,  i;};
	vector<e> v(n);
	for(int i = 0;i< n; i++){
	    e eo;
	    cin>>eo.a>>eo.b>>eo.c;
		eo.i = i;
		v[i]=eo;
	}

	sort(v.rbegin(), v.rend(), [](e& x, e& y){
	    return x.a*x.b -x.c < y.a*y.b - y.c;
	});
	int sum = 0;
	for(auto& x : v){
	    sum += x.a *(x.b-1);
	}
	dist -= sum;
	if(dist <= 0){
	    cout << 0 << endl;
		return;
	}
	auto mx = v.front();
	if(mx.a*mx.b - mx.c <= 0){
	    cout << -1 << endl;
		return;
	}
	dist += mx.a* mx.b-mx.c;
	cout << (dist-1)/(mx.a*mx.b - mx.c) << endl;
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
