#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n; cin>> n;
  char c; cin>> c;
  string s; cin>> s;
  int even_count = 0;
  int odd_count = 0;
  for(int i = 0; i< n; i++)
  {
    if(s[i] != c){
      if((i+1)&1)odd_count++;
      else even_count++;
    }
  }

  if(!even_count && !odd_count)cout<< 0 << endl;
  else if(!even_count && odd_count){ // only odd indices
    cout<< 1 << endl << 2<<endl;
  }else if(even_count && !odd_count){ // only even indices
    if(n&1){ // n is odd
      cout << 1 << endl << n << endl;
    }else{  // n is even
      cout << 1 << endl << n-1 << endl;
    }
  }else if(even_count && odd_count){ // both even and odd indices
    if(s[n-1] != c){ // if nth index is also to be changed
      // try to find the maximum odd indices > n/2 which is not to be changed
      int ans = -1;
      for(int i = n-2; i >= n/2; i--){
        if(s[i] == c){
          ans = i+1;
          break;
        }
      }
      if(ans != -1){
        cout << 1 << endl << ans << endl;
      }else{
        if(n&1){// if n is odd
          cout << 2 << endl << 2 << " " <<  n << endl;
        }else{ // if n is even
          cout<< 2 << endl << n <<" "<< n-1 << endl;
        }
      }
    }else{// if nth index is not to be changed
      cout <<  1 << endl << n<< endl;
    }
  }
  
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  auto begin = std::chrono::high_resolution_clock::now();
  freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
  freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
  int tt = clock();
  #endif
  
  int t = 1;
  if(multi)cin>> t;
  while(t--){
  Solve();
  // cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}