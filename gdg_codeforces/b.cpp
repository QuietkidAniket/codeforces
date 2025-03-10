#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int find_first_occur_or_lower_bound(vector<int>& arr, int target){
    int low =0, high= arr.size()-1;
    while(low <= high){
        int mid= low + (high - low)/2;
        if(arr[mid] <= target)low = mid +1;
        else high = mid -1;
    }
    return high;
}

void Solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin>> k;
    vector<pair<int,int>> q(k);
    for(int i = 0; i< k; i++)
    {
        pair<int,int> p;
        cin>> p.first >> p.second;
        q[i] = p;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0 ; i<k;i++){
        int l = q[i].first, r = q[i].second;
        int left = (lower_bound(arr.begin(), arr.end(), l)- arr.begin());
        int right = find_first_occur_or_lower_bound(arr, r);
        cout << right- left +1<< " ";
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

    Solve();
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}