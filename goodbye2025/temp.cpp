#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> l(n, vector<int>(2));
    for(int i=0;i<n;i++){
        cin >> l[i][0];
        l[i][1] = i;
    }
    sort(l.begin(), l.end());

    if(m > n/2){
        cout << -1 << endl;
        return;
    }
    if(m == 0){
        int sum= 0;
        for(int i=0; i<n-1; i++) sum+= l[i][0];
        
        if(sum < l[n-1][0]){
            cout << -1 << endl;
            return;
        }

        vector<int> w;
        vector<int> a;

        int summ= sum - l[n-2][0];

        int curr = summ;
        
        for(int i=0; i<n-2; i++){
            if(curr >= l[n-1][0]){
                w.push_back(i);
                curr -= l[i][0];
            } else {
                a.push_back(i);
            }
        }

        if(curr + l[n-2][0] < l[n-1][0]){
            cout << -1 << endl;
            return;
        }

        cout << n-1 << endl;

        for(int i=0;i<w.size();i++){
            int indexa = w[i];
            int indexb;
            
            if(i == w.size() - 1){
                indexb = n-2;
            } else {
                indexb = w[i+1];
            }
            cout << l[indexa][1]+1 << " " << l[indexb][1]+1 << endl;
        }
        for(int idx : a){
            cout << l[idx][1]+1 << " " << l[n-1][1]+1 << endl;
        }
        cout << l[n-2][1]+1 << " " << l[n-1][1]+1 << endl;
        return;

    }
    cout << n-m << endl;
    for(int i=m;i<n;i++){
        cout << l[i][1]+1 << " " << l[i-m][1]+1 << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test=1;
cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}