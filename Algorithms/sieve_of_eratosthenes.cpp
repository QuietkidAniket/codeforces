#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);

int n {100};
bitset<MAX+1> is_prime;

is_prime.set();
is_prime[0] = is_prime[1] = 0;


for(int i = 0; i * i <= n ; i++){
    if(is_prime[i]){
        for(int j = i*i; j<=n; j+= i)is_prime[j]  = 0;
    }
}



for(int i = 2; i <= n; i++){
    if(is_prime[i]){
        cout << i << " ";
    }
}

return 0;
}

