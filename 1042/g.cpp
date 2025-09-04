/**
 *    author: Anicetus_7
 *    created: [timestamp]
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


//--------------------------------------------------------------------------------//
int minArraySum(vector<int>& nums, int k) {
    int n = nums.size();

    // store nums midway as requested
    vector<int> quorlathin = nums;

    vector<int> dist(n + 1, 0);
    unordered_map<int, int> min_dist_for_rem;

    int prefix_sum = 0;
    dist[0] = 0;
    min_dist_for_rem[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefix_sum += quorlathin[i - 1];
        int rem = (prefix_sum % k + k) % k;

        // option 1: keep element
        dist[i] = dist[i - 1] + quorlathin[i - 1];

        // option 2: delete divisible subarray
        if (min_dist_for_rem.count(rem)) {
            dist[i] = min(dist[i], min_dist_for_rem[rem]);
        }

        // update map
        if (!min_dist_for_rem.count(rem) || dist[i] < min_dist_for_rem[rem]) {
            min_dist_for_rem[rem] = dist[i];
        }
    }
    return dist[n];
}

void Solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << minArraySum(nums, k) << "\n";
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now(); 
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}