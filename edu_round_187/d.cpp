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
#define Al cout<<"Alice\n";
#define Bo cout<<"Bob\n";
void Solve(){
	int n; cin>>n;
	int m; cin>>m;
	vector<int> a(n), b(m);
	for(auto& x : a)cin>> x;
	for(auto& x : b)cin>> x;
	
	unordered_set<int> st(a.begin(), a.end());
	vector<int> divs(n+m+1,0);
	for(int i: st){
	    for(int j = 1; i*j<=n+m; j++)divs[j*i]++;
	}

	int valids = 0, invalids = 0, boths = 0;
	for(int x : b){
	    int cnt =divs[x];
		if(cnt == st.size())valids++;
		else if(cnt > 0)boths++;
		else invalids++;
	}
	
	if(boths&1){
	    if(valids < invalids)Bo
		else Al
	}else{
	    if(valids <= invalids)Bo
		else Al
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
