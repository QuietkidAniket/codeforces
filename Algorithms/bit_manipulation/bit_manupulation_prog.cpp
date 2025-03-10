#include <bits/stdc++.h>
using namespace std;

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);


int x = 256;

// bit set
for(int i = 0; i< 32; i++)
{
    if(x&(1<<i))cout << i << ' ';
}


int n = 0;
n |= (1);
n |= (1<<1);
n |= (1<<3);

cout << n << '\n';

return 0;
}