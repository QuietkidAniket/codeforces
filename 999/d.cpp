#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
#define ll long long
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
static const int mod = 1000000007;

void Solve(){
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i = 0; i< n; i++)
    {
     cin>> arr[i];
    }

    if(arr[0] > arr[1] || ( n>= 3 && arr[1] - arr[0] > arr[2 ] )){
        cout << "NO";
        return;
    }
    int ptr= 0;
    for(int i= 2; i < n; i++){
        if(arr[i] < arr[i-1]){
            for(int j = ptr; j < i-1; j++){
                arr[j+1] = arr[j+1] - arr[j];
                arr[j] = 0;
            }
            ptr = i-1;
            if(arr[i] < arr[i-1]){
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
    
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
    
    int t;
    cin>> t;
    while(t--){
    Solve();
    cout << endl;
    }
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}