/**
 * author: Anicetus_7
 * created: 2r26-01-20 23:52:02
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(200005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());



void Solve(){
    string s = "_a_ _e___";
    set<char> st = {'a', 'e', 'i', 'o', 'u'};
    function<void(int)> find = [&](int ind)->void{
        if(ind == s.size()){
            cout << s << endl;
            return;
        }
        if(s[ind] != '_')
        {
            
            find(ind+1);

            return;
        }
        
        for(char c = 'a'; c <= 'z'; c++){
            if(st.count(c))continue;
            s[ind] = c;
            find(ind+1);
            s[ind] = '_';
        }
    };
    find(0);
}


//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
  auto begin = std::chrono::high_resolution_clock::now();
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  //cin >> t;
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

