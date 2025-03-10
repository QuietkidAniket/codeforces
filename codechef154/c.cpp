#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int,int> mi;
typedef vector<ll> vl;

bool can_convert_to_k(const vl &arr, ll st, ll e, ll k) {
    bool gcd_possible = true, xor_possible = true;
    ll f_xor = (arr[st] ^ k);
    for (ll i = st; i <= e; i++) {
        if ((arr[i] % k) != 0) gcd_possible = false;
        if ((arr[i] ^ k) != f_xor) xor_possible = false;
    }
    return (gcd_possible || xor_possible);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vl arr(n);
        for (int i=0;i<n;i++)
            cin>>arr[i];
        
        bool all_same=true;
        for (int i=0;i<n;i++) {
            if (arr[i] != k) {
                all_same=false;
                break;
            }
        }
        
        if (all_same) {
            cout<<0<< endl;
        } 
        else {
            int st=-1,e=-1;
            for (int i= 0;i<n;i++) {
                if (arr[i]!=k) {
                    if (st==-1) st=i; 
                    e=i;
                }
            }
            
            
            if (st==e) {
                cout << 1 << endl;
            } else {
                if (can_convert_to_k(arr,st,e,k)) {
                    cout<<1<<endl;
                } else {
                    cout<<2<<endl; 
                }
            }
        }
    }

    return 0;
}
