#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int find(vector<int> arr, int target1, int target2){
    // finds the first occurence
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] >= target1)high = mid -1;
        else low = mid +1;
    }
    int first = low;
    low = 0, high = arr.size()-1;
    // finds the last occurence
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] <= target2)low = mid +1;
        else high = mid -1;
    }
    return high - first+1;
}


void Solve(){
    int n;
    cin>>n;
    unordered_map<int,vector<int>> freq;
    for(int i = 0; i< n; i++)
    {
        int n;
        cin>> n;
        freq[n].push_back(i);
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q);
    for(int i = 0; i< q; i++)
    {
        vector<int> p(3);
        cin>> p[0] >> p[1] >> p[2];
        queries[i] = p;
    }
    
    for(int i = 0;i < q;i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int x = queries[i][2];
        cout << find(freq[x], l-1, r-1) << "\n";
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