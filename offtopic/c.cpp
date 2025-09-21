/**
 *    author: Anicetus_7
 *    created: 2025-09-21 08:25:00
**/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define MOD (int)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> generateMoves(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> res;
    for (int L = 0; L < n; L++) {
        for (int R = L; R < n; R++) {
            // Subarray to cut
            vector<int> sub(arr.begin() + L, arr.begin() + R + 1);

            // Remaining array
            vector<int> rem;
            for (int i = 0; i < L; i++) rem.push_back(arr[i]);
            for (int i = R + 1; i < n; i++) rem.push_back(arr[i]);

            // Insert sub in all possible positions
            for (int pos = 0; pos <= (int)rem.size(); pos++) {
                vector<int> newArr;
                for (int i = 0; i < pos; i++) newArr.push_back(rem[i]);
                newArr.insert(newArr.end(), sub.begin(), sub.end());
                for (int i = pos; i < (int)rem.size(); i++) newArr.push_back(rem[i]);
                res.push_back(newArr);
            }
        }
    }
    return res;
}

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t h = 0;
        for (int x : v) {
            h ^= std::hash<int>()(x) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        }
        return h;
    }
};

void Solve(){
    int n; cin >> n;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++) cin >> nums1[i];
    for (int i = 0; i < n; i++) cin >> nums2[i];



    queue<vector<int>> q;
    unordered_map<vector<int>,int, VectorHash> dist;


    q.push(nums1);
    dist[start] = 0;
    while(!q.empty()){
        auto node = q.front(); q.pop();
        if(node == target){
            return dist[node];
        }
        auto res = find(node);
        for(auto adjnode : res){
            if(dist.find(adjnode) == dist.end()){
                dist[adjnode] = dist[curKey] + 1;
                q.push(adjnode);
            }
        }
    }

}

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