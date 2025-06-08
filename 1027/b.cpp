#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n, k; cin>>n >>k;
  string s; cin>> s;

  int left = 0, right = n-1;
  int cnt = 0;
  if(k > n/2){
    cout << "NO";
    return;
  }
  while(left<=right){
    if(s[left] != s[right])cnt++;
    left++, right--;
  }

  int good_pairs = n/2 - cnt;
  if(good_pairs == k)cout << "YES";
  else if(good_pairs <k){
    if((k - good_pairs)%2 == 0){
      int z = (k - good_pairs);
      if(cnt >= z)cout << "YES";
      else cout << "NO";
    }else cout<< "NO";
  }else{
    if((good_pairs - k)%2 == 0){
      cout << "YES";
    }else cout<< "NO";
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
  cout << endl;
  }
  #ifndef ONLINE_JUDGE
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
  #endif
  return 0;
}