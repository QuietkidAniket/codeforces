#include <bits/stdc++.h>
using namespace std;

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}


void find(int index, const vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
    if(index == nums.size()){
        ans.push_back(ds);
        return;
    }
    // we choose nums[index]
    ds.push_back(nums[index]);
    find(index+1, nums, ans, ds);
    ds.pop_back();
    // we do not choose nums[index];
    find(index+1, nums, ans, ds);
}
    
void solve(){
    int n, target;
    cin>> n >> target;
    vector<int> nums(n);

    for(int i = 0; i< n; i++)
    {
        cin >> nums[i]; 
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> ds;
    find(0, nums, ans, ds);

    for(const auto& arr : ans)
    {   
        cout << "{";
        for(const auto& x : arr)
        {
            cout << x <<  ",";
        }
        cout << "}\n";
    }
}