#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

int ans = 0;


void Solve(){
  ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;

    map<int,int> mp;
    for(int i =0 ; i < n; i++){
        mp[arr[i]] = i;
    }

    int cnt = 0;
    set<int> prev;
    set<int> curr;
    for(int i = 0; i < n; i++){
        if(i < mp[arr[i]] ){
            prev.erase(arr[i]);
            curr.insert(arr[i]);
            if(prev.empty()){
                cnt++;
                prev= curr;
            }
        }else{
            cnt++;
            break;
        }
    }
    cout << cnt;
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