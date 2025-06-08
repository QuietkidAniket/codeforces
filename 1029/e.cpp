#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
  ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(auto& i: a){
        cin >> i;
    }
    for(auto& i: b){
        cin >> i;
    }
    map<ll, ll> mpa, mpb;

    ll ind=-1;

    if(a[n-1] == b[n-1]){
        cout << n;
        return;
    }
    

    for(ll i = n-2; i >= 0; i--){
        mpb[b[i+1]]++;
        if(mpb.find(b[i]) !=  mpb.end() || a[i] == b[i]){
            ind = i;
            break;
        }
        mpb[a[i+1]]++;
    }

    for(ll i=n-2;i>=0;i--){
        mpa[a[i+1]]++;
        if(mpa.find(a[i]) !=  mpa.end() || a[i] == b[i]){
            ind = max(ind, i);
            break;
        }
        mpa[b[i+1]]++;
    }
    cout << ind+1;
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