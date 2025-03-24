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
    
    #ifndef ONLINE_JUDGEJUDGE
        cerr << "TIME = " << clock() - tt << endl;
        tt = clock();
    #endif
    return 0;
}
void solve(){
    int t;
    cin >>t;
    while(t--){
        int n, x,y;
        cin>>n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i< n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        set<int> st;
        for(int i = 0; i < n ; i++){

        }

    }
}

