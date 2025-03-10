#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int check(int x, vector<int>& arr, int k){
    int count = 0;
    for(const auto num : arr){
        if(num <= x)count++;
    }
    return count;

}

void Solve(){
    int n, k;
    cin >> n >>k;
    vector<int> arr(n);
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int low = 1, high = 1e9;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        int res = check(mid, arr, k);
        if(res == k){
            ans = mid;
            high = mid -1;
        }else if(res > k)high = mid -1;
        else low = mid +1;
    }
    cout << ans;
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

    Solve();
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}