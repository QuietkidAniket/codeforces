#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  int n,x;
  cin>> n>>x;
  vector<ll> a(n);

  for(int i = 0; i< n; i++)
  {
    cin>> a[i];
  }
  int max_length= 1, curr_length =1;
  for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            curr_length++;
        } else {
            curr_length = 1;
        }
        max_length = max(max_length, curr_length);
    }

    for (int i = 0; i < n; i++) {
        ll temp = a[i];
        a[i] *= x;

        int left = i, right = i;
        while (left > 0 && a[left - 1] <= a[left]) left--;
        while (right < n - 1 && a[right] <= a[right + 1]) right++;

        max_length = max(max_length, right - left + 1);
        a[i] = temp;
    }

    cout << max_length;
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