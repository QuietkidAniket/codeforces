#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}
void solve(){
    int t;
    cin>> t;
    while(t--){
        int n, k;
        cin>> n >>k;
        int arr[n];
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        for(int i = 0; i< n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        if(n <= k){
            cout<< 1 << '\n';
            continue;
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            pq.push({it->second, it->first});
        }

        int ans= 0;
        while(!pq.empty()){
            int num = pq.top().second;
            int freq = pq.top().first;
            // cout << num << " removed \n";
            pq.pop();
            if(n > k){
                n -= freq;
                ans++;
            }
            else if(n <=k){
                break;
            }   
        }
        cout << ans;

        cout << '\n';
    }
    
}