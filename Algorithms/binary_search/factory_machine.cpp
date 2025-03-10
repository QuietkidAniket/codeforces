#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());



bool check(int days, vector<int>& arr, int target){
    int count= 0;
    for(const auto& x : arr){
        count += (x / days);
    }
    return days <= target;
}

void Solve(){
    int n, k;
    cin >> n>> k;
    vector<int> arr(n);
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int low = 0, high = 1e5;
    if(low <= high){
        int mid = low + (high - low)/2;
        if(check(mid, arr, k)){
            high = mid -1;
        }else low  = mid +1;
    }
    cout << low;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    
    int t;
    cin>> t;
    while(t--)
    Solve();
    cout << '\n';
    
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}