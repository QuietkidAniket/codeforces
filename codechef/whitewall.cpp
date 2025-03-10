#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

static string dir[] = {
  "RGB",
  "RBG",
  "GRB",
  "GBR",
  "BRG",
  "BGR",
};

ll find(const string& s, const string& a, const int n){ 
  ll count = 0;
  for(int i = 0; i < n; i+=3){
    for(int j = i; j < min(n, i+3); j++){
      if(a[j%3] == 'R' && s[j] != 'R')count++;
      else if(a[j%3] == 'G' && s[j] != 'G')count++;
      else if(a[j%3] == 'B' && s[j] != 'B')count++;
    }
  }
  return count;
}

void Solve(){
  int n;
  string s;
  cin>> n;
  cin>> s;
  ll min_count = INT_MAX;
//   if(n <=3){
//     set<char> st(s.begin(), s.end());
//     cout << n-st.size();
//     return;
//   }

  for(const auto& comp : dir){
    min_count = min(min_count, find(s, comp, n) );
  }
  cout << min_count ;
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