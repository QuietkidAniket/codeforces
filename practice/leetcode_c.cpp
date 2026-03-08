#define ll long long
#define vii vector<int>
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n  = nums.size();
        vector<vector<int>> a(n, vector<int>(3));
        for(int i =0 ;i  < n ;i++){
            a[i] = {nums[i], colors[i], i};
        }
        sort(a.begin(), a.end(), [&](const vii& x, const vii& y){
            if(x[0] == y[0])return x[2] < y[2];
            return x[0] > y[0];
        });

        set<int> st;
        ll sum = 0;
        for(int i =0 ;i < n; i++){
            int col = a[i][1];
            int idx =  a[i][2];
            if((st.count(idx -1) && colors[idx-1]==col) || (st.count(idx+1)&& colors[idx+1] == col))continue;
            else{
                sum += a[i][0];
                st.insert(idx);
            }
        }
        return sum;
    }
};©leetcode
