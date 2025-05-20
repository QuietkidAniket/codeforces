#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n; cin>> n;
  string s; cin>> s;
  int ans = 1e9;
  for(char c = 'a' ; c <= 'z'; c++){
    int left = 0, right = s.size()-1;
    // we try to form a palindrome
    // we only remove character c if it does not form a palindrome
    // flag = true when palindrome cannot be formed by only removing c
    bool flag = false;
    int count = 0;
    while(left<= right){
      if(s[left] == s[right]){
        left++, right--;
      }else{
        if(s[left] == c){
          left++;
          count++;
        }else if(s[right] == c){
          right--;
          count++;
        }else{
          flag = true;
          break;
        }
      }
    }
    if(flag)continue;
    else ans = min(ans, count);
  }

  if(ans == 1e9)cout << -1;
  else cout << ans;
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
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}