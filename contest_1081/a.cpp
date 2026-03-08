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
	string s; cin>>s;

	int cnt =0, idx = 0, mxlen  =0;
	for(int i = 1; i <n ; i++){
	    if(s[idx] != s[i]){
			cnt++;
			mxlen = max(mxlen,i-idx);
			idx = i;
		}
	}
	mxlen = max(mxlen,n-idx);
	cnt++;
	if(s[0] == s[n-1] || mxlen < 2){
	    cout <<cnt <<endl;
	}else{
	    cout << cnt + 1<< endl;
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