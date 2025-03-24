#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);


int t;
cin >>t;

while(t--){
    int n;
    int max_even = INT_MIN, max_odd = INT_MIN;
    for(int i = 1; i <= n; i++){
        int x;
        cin >>x;
        if(i & 1)max_odd = max(max_odd, x);
        else max_even = max(max_even, x);
    }


if(n&1){
    cout << max(max_even + n +1, max_odd + n) << '\n';
}else{
    cout << max(max_even + n, max_odd + n) << '\n';
}

}
return 0;
}