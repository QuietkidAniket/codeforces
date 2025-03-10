#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;
static const ll INF = ll(1E18)+16;
vector<int> b;

int l_bound(int prev, int curr){
  int low = 0, high = b.size()-1;
  int ans = -1;
  // binary search for the smallest number b[mid] - curr greater than prev
  while(low <= high){
    int mid = (low+ high)/2;
    if(b[mid] - curr >= prev){ans = mid; high = mid -1;}
    else low = mid +1;
  }
  return ans;
}


void Solve(){
  int n,m;
  cin>> n>>m;
  vector<int> a(n);
  b.resize(m);
  for(int i = 0; i< n; i++)
  {
    cin>> a[i];
  }
  for(int i = 0; i< m; i++)
  {
    cin>> b[i];
  }
  if(n == 1){cout << "YES"; return;}

  sort(b.begin(), b.end());
  a[0] = min(b[0]-a[0], a[0]);

  for(int i = 1; i< n; i++)
  {

    int res = l_bound(a[i-1], a[i]);
    if(res == -1)continue;
    // a[i] = min(b[res]-a[i], a[i]);
    if(a[i] < a[i-1] && b[res] - a[i]< a[i-1])continue;

    a[i] = min(a[i] < a[i-1] ? INF: a[i], b[res] - a[i] < a[i-1]? INF: b[res]- a[i]);
  }
  if(is_sorted(a.begin(), a.end()))cout << "YES";
  else cout << "NO";
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