#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}

class Solution {
  public:
    // Naive approach
    long double findSmallestMaxDist_Naive(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howMany(n-1,0);
        for(int gasStations = 0; gasStations < k; gasStations++){
            long double maxSection = -1, maxIndex = -1;
            for(int i = 0; i < n-1;i++ ){
                long double section = (stations[i+1] - stations[i])/ (long double)(howMany[i] +1);
                if(maxSection < section){
                    maxSection = section;
                    maxIndex = i;
                }
            }
            // we put a station at the maximum gap index
            howMany[maxIndex]++;
        }

        long double ans = -1;
        for(int i = 0; i < n-1;i++ ){
            long double section = (stations[i+1] - stations[i])/(long double) (howMany[i] +1);
            ans = max(ans, section);
        }
        return ans;
    }

    // Heap Approach
    long double findSmallestMaxDist_Heap(vector<int> &stations, int k) {
        int n = stations.size();
        priority_queue<pair<long double,int>> pq;
        vector<int> howMany(n-1, 0);
        for(int i =0 ; i < n-1; i++){
            pq.push({stations[i+1] - stations[i], i});
        }
        for(int gasStations = 0; gasStations < k; gasStations++){
            auto max_section = pq.top(); pq.pop();
            howMany[max_section.second]++;
            long double section = (stations[max_section.second+1] -stations[max_section.second]) / (long double)(howMany[max_section.second] +1);
            pq.push({section, max_section.second});
        }
        return pq.top().first;
    }

    // Binary Search approach
    long double findSmallestMaxDist_BinarySearch(vector<int> &stations, int k) {

        long double ans = -1;
        return ans;
    }
};


void solve(){
    int t;
    cin>>t;
    while(t--){
    int n, k;
    cin>> n >>k;
    vector<int> arr(n);
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    Solution obj;
    cout << (long double)obj.findSmallestMaxDist_Heap(arr, k) <<'\n';
    }
}