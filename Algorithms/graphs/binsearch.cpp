#include <bits/stdc++.h>
using namespace std;

void solve(){
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,12,15,16,19,26};
    int left= 0, right = 15;
    int key;
    cin>> key;
    int mid;
    while(left <= right){
        mid = (left+ right) >>1;
        if(key == arr[mid]){
            cout << mid;
            break;
        }
        else if (key > arr[mid])left = mid +1;
        else right = mid-1;
    }
    cout << "\n" << arr[left] << '\n' << arr[right];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    solve();
    
    
    return 0;
}