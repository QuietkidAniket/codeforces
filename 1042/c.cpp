/**
 *    author: Anicetus_7
 *    created: 2025-08-10 20:20:59
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define vi vector<int>


void Solve(){
    int n,k; 
    cin >> n >> k;
    vi a(n), b(n);
    for(auto& x : a)cin>> x;
    for(auto& x : b)cin>> x;

    for(int i = 0; i< n; i++)
    {
        a[i] %= k;
        a[i]  = min(a[i], k - a[i]);
        b[i] %= k;
        b[i]  = min(b[i], k - b[i]);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a==b)cout << "YES\n";
    else cout << "NO\n";
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) Solve();
}