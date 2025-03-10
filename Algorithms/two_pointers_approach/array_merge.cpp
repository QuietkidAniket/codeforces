#include <iostream>
#include <vector>
using namespace std;

// @author: Anicetus
/*
    Two pointer method for merging two sorted arrays in sorted fashion
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n+m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];

    int i{0}, j{0};
    while(i < n || j < m)
    {
        if(j== m || i < n && a[i] < b[j]){
            c[i + j] = a[i];
            i++;
        }else{
            c[i + j] = b[j];
            j++;
        }
    }
    for(const auto& x : c){
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}