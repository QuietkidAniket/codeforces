#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int32_t arr[4];
    memset(arr, 0xFF, sizeof(arr));
    for(auto x : arr){
        cout << "Bit representation of  "<< x<<" : " << '\n';
        cout << ( bitset<32> )x << '\n';
    }  
}