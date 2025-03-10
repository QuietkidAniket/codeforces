#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n, m, k;
    cin >> n >> m >> k;

    int a[m];
    unordered_map<int,bool> q;
    for(int i = 0; i< m; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i< k; i++)
    {
        int x;
        cin>> x;
        q[x] = true;
    }
    for(int i = 0; i < m ;i++){
        if( k < n-1 || (q[a[i]] && k != n))cout << 0;
        else cout << 1;
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