#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    int n,q;
    cin >> n >>q;
    int k[q];
    int missing[n];
    for(int i = 0; i< n; i++)
    {
        int x;
        cin >>x;
        missing[i] = x - (i+1);
    }
    for(int i = 0; i< q; i++)
    {
        cin >> k[i];
    }

    for(int i = 0; i < q; i++){
        // searching for the smallest index where missing is > k
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(missing[mid] >= k[i])high = mid -1;
            else low = mid +1;
        }
        cout<< k[i] + low<< '\n';
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
    
    // int t;
    // cin>> t;
    // while(t--){
    Solve();
    // cout << '\n';
    // }
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}