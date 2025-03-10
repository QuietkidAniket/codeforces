#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
bool multi = true;
static const int mod = 1e9 + 7;


void Solve(){
    ll n, l, r;
    cin>> n>> l >>r;
    vector<ll> mid;
    vector<ll> left;
    vector<ll> right;
    for(int i = 0; i< n; i++)
    {
        int x;
        cin >>x;
        if(i >= l -1 && i <= r -1){
            mid.emplace_back(x);    
        }else if(i < l -1)left.emplace_back(x);
        else right.emplace_back(x);
    }


    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    sort(mid.begin(), mid.end());

    ll sum1 = 0;
    int lptr = 0;
    for(int i = mid.size()-1; i >=0 ; i--){
        if(lptr < left.size() && mid[i] > left[lptr]){
            sum1 += left[lptr];
            lptr++;
        }else{
            sum1 += mid[i];
        }
    }
    ll sum2 = 0;
    int rptr = 0;
    for(int i = mid.size()-1; i >=0 ; i--){
        if(rptr < right.size() && mid[i] > right[rptr]){
            sum2 += right[rptr];
            rptr++;
        }else{
            sum2 += mid[i];
        }
    }
    cout<< min(sum1, sum2) <<" ";
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