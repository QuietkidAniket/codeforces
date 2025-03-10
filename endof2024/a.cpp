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

bool find(int index, const vector<int>& arr, vector<int>& ds);

int subset(int index, const vector<int>& arr,vector<vector<int>>& ds){
    if(index == arr.size()){
        cout << "sub array : [ ";
        bool flag = false;
        for(auto subarray: ds){
            vector<int> temp;
            // cout << "[";
            // for(const auto& x: subarray){
            //     cout<< x << ", ";
            // }
            // cout << "]";
            if(!find(0, subarray, temp)){
                flag = true;
            }
        }
        cout << " ] -> " << !flag <<'\n';
        if(!flag){
            return 1;
        }else return 0;
    }
    int count = 0;
    for(int i = index;i < arr.size(); i++){
        vector<int> subarray(arr.begin()+ index, arr.begin()+i+1);
        ds.push_back(subarray);
        count += subset(i +1,arr, ds);
        ds.pop_back(); 
    }
    return count;
}   

bool find(int index, const vector<int>& arr, vector<int>& ds){
    if( ds.size() == 3){
        if(ds[0] +ds[1] > ds[2] && ds[0] + ds[2] > ds[1] && ds[1] + ds[2] > ds[0]){
            cout << "( "<< ds[0] << ", " << ds[1] << ", " << ds[2] << " )\n";
            return true;
        }
        return false;
    }
    if(index == arr.size())return false;
    ds.push_back(arr[index]);
    bool ans = find(index, arr, ds);
    ds.pop_back();
    return ans || find(index +1, arr,ds);
}



void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i< n; i++)
        {
            cin >> arr[i];
        }
        vector<vector<int>> ds;
        int count= subset(0, arr, ds);
        cout << "count : " << count <<", ";
        if(count >=2 ){
            cout << "YES\n";
        }else cout << "NO\n";
    }
}
