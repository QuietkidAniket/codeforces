#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;

int f(string s){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += s[i] - 'a' + 1;
    }
    return sum;
}

void Solve(){
    int n;
    cin>> n;
    vector<int> arr(n);
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    auto end = unique(arr.begin(), arr.end());
    arr.resize(distance(arr.begin(), end));
    n = arr.size();
    if(n == 1){cout << 1; return;}

    int count = 2;
    for(int i = 1; i < n-1; i++){
        if((arr[i-1] < arr[i] && arr[i] < arr[i+1]) || (arr[i-1] > arr[i] && arr[i] > arr[i+1]))continue;
        else count++;
    }
    cout << count;
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
    
    int t = 1;
    if(multi)cin>> t;
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