#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
static const int mod = 1000000007;

void Solve(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i = 0; i< n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i< n; i++)
    {
        cin >> b[i];
    }
    int target = -1;
    int least = INT_MAX;
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
            if(target == -1 ){
                target = b[i] - a[i];
            }else{
                cout << "NO";
                return;
            }
        }else{
            least  = min(least, a[i] - b[i]);
        }
    }
    if(target <= least)cout<<"YES";
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
    
    int t;
    cin>> t;
    while(t--){
    Solve();
    cout << '\n';
    }
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}