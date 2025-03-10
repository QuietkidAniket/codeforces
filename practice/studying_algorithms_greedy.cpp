#include <bits/stdc++.h>
using namespace std;

void solve(){
    // no. of total tasks
    int n;
    cin>> n;
    // used for storing the time required for each task
    vector<int> arr(n);

    // a[i] time required for each task
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    // maximum amount of time available
    int x;
    cin>>x;

    /*
        Need to find the maximum number of tasks that can be done within x time
    */


    // sort the tasks on basis of time from lowest to highest
    sort(arr.begin(), arr.end());

    int i = 0;
    int count = 0;
    int no_of_tasks = 0;
    while(i < n && count + arr[i] <= x){
        count += arr[i];
        no_of_tasks++;
        i++;
    }

    cout << no_of_tasks << " is the Maximum number of tasks that can be done within " << x << " time and it takes " << count << " time \n";

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("/Users/aniketkundu12072004/codeforces/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/codeforces/output.out", "w", stdout);
    solve();
    
    
    return 0;
}