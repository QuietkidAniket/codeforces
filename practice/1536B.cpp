/**
 *    author: Anicetus_7
 *    created: 2025-12-15 20:58:39
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

  for(char a= 'a' ; a<= 'z' ; a++){
    if(s.find(a) == string::npos){
      cout << a<< endl;
      return;
    }
  }
  for(char a= 'a' ; a<= 'z' ; a++){
    for(char c= 'a' ; c<= 'z' ; c++){
      string t; 
      t.push_back(a);
      t.push_back(c);
      if(s.find(t) == string::npos){
        cout << t<< endl;
        return;
      }
    }
  }
  for(char a= 'a' ; a<= 'z' ; a++){
    for(char c= 'a' ; c<= 'z' ; c++){
    for(char d= 'a' ; d<= 'z' ; d++){
        string t; 
        t.push_back(a);
        t.push_back(c);
        t.push_back(d);
        if(s.find(t) == string::npos){
          cout << t<< endl;
          return;
        }
      }
    }
  }
  cout << "aaaa" <<endl;
  
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


