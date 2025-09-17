/**
 *    author: Anicetus_7
 *    created: 2025-09-13 20:41:52
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
#define MAX (int)(20005)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    int n, k; cin>>n>>k;
    vector<int> a(n);
    vector<int> freq(n+1,0);
    for(auto& x : a){
        cin>> x;
        freq[x]++;
    }

    for(auto x :  freq){
        if(x%k != 0){
            cout << 0 << endl;
            return;
        }
    }

    vector<int> w(n+1,0);
    int l=0, r = 0;
    int ans =0 ;
    while(r < n){   
        w[a[r]]++;
        while(w[a[r]] > freq[a[r]]/k && l < r){
            w[a[l]]--;
            l++;
        }
        ans += r-l+1;
        r++;
    }
    cout << ans  << endl;

}

int32_t main() {
    auto begin = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) Solve();
    auto end = chrono::high_resolution_clock::now(); 
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin); 
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}