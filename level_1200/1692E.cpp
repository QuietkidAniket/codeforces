#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n,s;
  cin>> n>>s;

  vector<int> prefix(n+1,0);

  for(int i = 0; i< n; i++)
  {
    int x; cin>> x;
    prefix[i+1] = prefix[i] + x;
  }

  if(prefix[n] < s){cout << -1;return;}

  int ans = 0;
  for(int i = 0; i< n; i++)
  {
    // if segment length to be kept is (index - i).
    // hence, try to maximize index
    // binary search for maximum index such that prefix[index] - prefix[i] == s
    int low = i, high = n, index = n-1;
    while(low <= high){;
      int mid = (low + high)/2;
      if(prefix[mid] - prefix[i] <= s){
        index = mid-1;
        low = mid + 1;
      }else if(prefix[mid] - prefix[i] > s) high = mid -1;
    }
    ans = max(ans, index - i+1);
  }
  cout << n-ans;
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