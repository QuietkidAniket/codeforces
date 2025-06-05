#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

void Solve(){
     ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0; i< m; i++)
    {
      cin >> a[i];
    }
    sort(a.begin(), a.end());

    for(int i=0;i<n;i++){
        ll mid = i/2;
        if(i%2==0){
            for(int j=0;j<3;j++){
                cout << a[m-1-mid] << " " << a[mid] << " ";
            }
        }
        else{
            for(int j=0;j<3;j++){
                cout <<  a[mid] << " " << a[m-1-mid] << " " ;
            }
          }
        cout << endl;

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
    if(multi) cin >> t;
    while(t--) {
        Solve();
    }

    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}