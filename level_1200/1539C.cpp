#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef unsigned long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  ll n, k, x; cin>> n>> k>>x;
  ll arr[n];
  for(int i = 0; i< n; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for(int i = 0; i< n-1; i++)
  {
    ll a = arr[i], b=  arr[i+1];
    if(b - a > x)pq.push(b-a);
  }
  while(pq.size() > 0 && k > 0){
    ll requirement = pq.top()/x;
    if(pq.top()%x == 0)requirement -= 1;
    if(requirement > k)break;
    else{
      k -= requirement;
      pq.pop();
    }
  }
  cout << pq.size()+1;
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