/**
 *    author: Anicetus_7
 *    created: 2025-08-03 09:09:56
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (ll)1e18
#define MOD (ll)(1e9 + 7)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &x : a) cin >> x;

    vector<ll> inc_l(n), inc_r(n), dec_l(n);
    vector<ll> pre(n); pre[0] = a[0];
    for(ll i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];

    inc_l[0] = 0;
    for(ll i = 1; i < n; ++i) {
        inc_l[i] = (a[i] > a[i - 1]) ? inc_l[i - 1] : i;
    }

    inc_r[n - 1] = n - 1;
    for(ll i = n - 2; i >= 0; --i) {
        inc_r[i] = (a[i] < a[i + 1]) ? inc_r[i + 1] : i;
    }

    dec_l[0] = 0;
    for(ll i = 1; i < n; ++i) {
        dec_l[i] = (a[i] < a[i - 1]) ? dec_l[i - 1] : i;
    }

    vector<ll> min_pre(n);
    for(ll i = 0; i < n; ++i) {
        if(inc_l[i] < i) {
            ll l = inc_l[i];
            min_pre[i] = (l > 0 ? pre[l - 1] : 0);
        } else min_pre[i] = INF;
    }

    vector<ll> max_pre_inc(n);
    for(ll i = n - 1; i >= 0; --i) {
        if(i == n - 1 || a[i] >= a[i + 1]) max_pre_inc[i] = pre[i];
        else max_pre_inc[i] = max(pre[i], max_pre_inc[i + 1]);
    }

    deque<ll> dq;
    ll ans = -INF;

    for(ll q = 1; q < n; ++q) {
        ll p = q - 1;
        if(min_pre[p] != INF) {
            while(!dq.empty() && min_pre[dq.back()] >= min_pre[p]) dq.pop_back();
            dq.push_back(p);
        }

        while(!dq.empty() && dq.front() < dec_l[q]) dq.pop_front();

        if(!dq.empty() && inc_r[q] > q) {
            ll best = dq.front();
            ll sum = max_pre_inc[q + 1] - min_pre[best];
            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';
}

//|------------------------------------------[MAIN]------------------------------------------|
int32_t main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0); cin.tie(0);
    ll t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++) {
        // cerr << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now(); 
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); 
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}