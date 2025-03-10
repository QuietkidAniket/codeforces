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


bool check(int min_dist, const int arr[], int n, int c){
    // check if c cows can be placed with minimum distance min_dist
    c--; // we anyways place the first cow in first stall
    int last = arr[0];
    for(int i = 1; i < n && c > 0; i++){
        if(arr[i] - last >= min_dist){
            last = arr[i];
            c--;
        }
    }
    return !c;
}

void solve(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>> n >>c;
        int arr[n];
        for(int i = 0; i< n; i++)
        {
            cin >> arr[i];
        }
        // search space : minimum distance between two cows which is possible
        // we search for the maximum here
        sort(arr, arr+n);
        int low =arr[0], high = arr[n-1];
        while(low <= high){
            int mid = (low+high)/2;
            if(check(mid, arr, n, c))low= mid+1;
            else high = mid-1;
        }
        cout << high << '\n';
    }
}