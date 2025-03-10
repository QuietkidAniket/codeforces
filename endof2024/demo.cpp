#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}

void find(int index, const vector<int>& arr, vector<int>& ds){
    if( ds.size() == 3){
        if(ds[0] +ds[1] > ds[2] && ds[0] + ds[2] > ds[1] && ds[1] + ds[2] > ds[0]){
        cout << "( "<< ds[0] << ", " << ds[1] << ", " << ds[2] << " )\n";
        }
        return;
    }
    if(index == arr.size())return;
    ds.push_back(arr[index]);
    find(index, arr, ds);
    ds.pop_back();
    find(index +1, arr,ds);
}

void solve(){
    vector<int> arr = {2, 3};
    vector<int> ds;
    vector<vector<int>> ans;
    cout << " ans : " ;
    find(0, arr,ds);
    // for(const auto& arr : ans)
    // {
    //     for(const auto& x : arr)
    //     {
    //         cout <<  x << ", ";  
    //     }
    //     cout << '\n';
    // }
    
}