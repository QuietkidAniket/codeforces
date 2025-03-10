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

    ans.push_back(ds);
    for(int i = index; i < nums.size(); i++){
        if(i > index && nums[i] == nums[i-1])continue;
        ds.push_back(nums[i]);
        find(i+1, nums, ans, ds);
        ds.pop_back();
    }
}


void solve(){
    int n, target;
    cin>> n;
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