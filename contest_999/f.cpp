#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
#define int long long
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
const ld eps = 1e-6;
static const int mod = 1e9;
const int inf = 1e9;
const int M = 1e9 + 7;
const ld pi = atan2(0, -1);

void Solve(){
    
    
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