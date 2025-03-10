#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

bool check(int capacity, const vector<int> weights, int d){
    int trips = 0;
    int sum = 0;
    for(const auto x : weights){
        if(sum + x > capacity){
            sum = x;
            trips++;
        }else{
            sum += x;
        }
    }
    if(sum > 0) trips++;
    return trips <= d;
}

void Solve(){
    int n, d;
    cin>> n >>d;
    vector<int> arr(n);
    int low = 1, high =0;
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
        low = max(low, arr[i]);
        high+= arr[i];
    }
    while(low <= high){
        int mid = low + (high -low)/2;
        if(check(mid, arr, d))high = mid-1;
        else low = mid +1;
    }
    cout << low;
    
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