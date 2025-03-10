#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int bin(int arr[], int n, int target){
    int low = 0, high  = n-1;
    while(low<=high){
        int mid = (high+low)>>1;
        if(arr[mid] ==target)return mid;
        else if (target> arr[mid]) low = mid + 1;
        else high = mid -1;
    }
    return -1;
}

int bin_recur(int arr[], int low, int high, int target){
    if(low <= high){
    int mid = (low+high)>>1;
    if(arr[mid] == target)return mid;
    else if(target > arr[mid])return bin_recur(arr, mid+1, high, target);
    else return bin_recur(arr, low, mid-1, target);
    }
    return -1;
}

int l_bound(int arr[], int low, int high, int target){
    int ans = high+1;
    while(low<= high){
        int mid = (low+high)>>1;
        if(target <= arr[mid]){
            ans = mid;
            high = mid -1;
        }else{
            low = mid+1;
        }
    }  
    return ans;
    // or 
    // return lower_bound(arr+low, arr+high+1, target) -arr+low;
}

int u_bound(int arr[], int low, int high, int target){
    int ans = low-1;
    while(low <=high){
        int mid = (low+high) >> 1;
        if(target < arr[mid]){
            ans = mid;
            high = mid -1
        }else low  = mid +1;
    }
    return ans;
    // or
    // return upper_bound(arr+low, arr+high+1, target) - arr + low;
}

int last_index(int arr[], int low, int high, int target){
    int ans = -1;
    while(low <= high){
        int mid =  low + (high- low)/2;
        if(arr[mid] <= target){
            ans = mid;
            low = mid +1;
        }
        else high = mid -1;
    }
    return ans;
}

void Solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin>> target;
    cout << "binary search : " << bin_recur(arr, 0, n-1, target);
    cout << "\nlower_bound : "  << l_bound(arr, 0, n-1, target);
    cout << "\nupper_bound : "  << u_bound(arr, 0, n-1, target);
    cout << "\nlast index : "  << last_index(arr, 0, n-1, target);
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    auto begin = std::chrono::high_resolution_clock::now();
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    
    int t;
    cin>> t;
    while(t--)
    Solve();
    cout << '\n';
    
    #ifndef ONLINE_JUDGE
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    #endif
    return 0;
}   