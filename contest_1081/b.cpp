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
	if(s == "10"){
	    cout << 1 << endl;
		cout << 2 << endl;
	}else if(s == "01"){
	    cout << 1 << endl;
		cout << 1 << endl;
	}else{
	    vector<int> o, z;
		for(int i  = 0 ; i < n; i++){
		    char c = s[i];
		    if(c == '1')o.push_back(i+1);
			else z.push_back(i+1);
		}
		if(z.size() % 2 == 1){
  		    cout << z.size() <<endl;
  		    for(auto& x: z)cout << x << " ";
 			cout << endl;
		}else if(o.size()%2 == 0){
  		    cout << o.size() <<endl;
  		    for(auto& x: o)cout << x << " ";
 			cout << endl;
		}else cout << -1 << endl;
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
