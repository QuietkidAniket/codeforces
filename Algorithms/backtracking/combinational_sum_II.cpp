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


void find(int index, const vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int sum,const int target){
    if(sum == target){
        ans.push_back(ds);
    }
    if(index == nums.size()){
        return;
    }
    for(int i =index; i< nums.size(); i++){
        if(nums[i] +sum > target)return;
        ds.push_back(nums[index]);
        find(i+1, nums, ans, ds, sum+nums[index], target);
        ds.pop_back();
    }
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
    find(0, nums, ans, ds, 0, target);

    for(const auto& arr : ans)
    {
        for(const auto& x : arr)
        {
            cout << x <<  ", ";
        }
        cout << '\n';
    }
}