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
	int a = n/2 + (n%2), b = n/2;
	bool flag= false;
	if(n%2==0){
	    if((s[0] == 'a' || s[0] == '?') && (s[1] == 'b' || s[1] == '?')){ // ab ...
			for(int i =2;i <n-1; i+=2){
			    if(s[i] == s[i+1] && s[i] != '?' ){
					flag= true;
					break;
				}
			}
		}else if((s[0] == 'b' || s[0] =='?') && (s[1] == 'a' || s[1] == '?')){ // ba ...
			for(int i =2;i <n-1; i+=2){
			    if(s[i] == s[i+1] && s[i] != '?'){
					flag= true;
					break;
				}
			}
		}else flag= true;
	}else{
	    if(s[0] == 'b'){
			flag = true;
	    }else for(int i =1;i <n-1; i+=2){
		    if(s[i] == s[i+1] && s[i] != '?'){
				flag= true;
				break;
			}
		}
	}
	if(flag){
	    cout << "NO\n";
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
