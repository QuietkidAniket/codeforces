#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> ans;
vector<int> arr_sorted;
vector<int> neg;
vector<int> pos;
int binarysearch(vector<int>& arr, int key, int low, int high){
    if(low > high)return -1;
    int mid = (low+high)/2; 
    if(arr[mid] == key) return mid;
    else if(arr[mid] <  key)return binarysearch(arr, key, mid+1, high);
    else return binarysearch(arr, key, low, mid-1);
    return -1;
}

bool check_triplet_already_present(int a, int b, int c){
    for(auto x: ans){
        if(x[0] == a && x[1] == b)return true;
        if(x[0] == b && x[1] == a)return true;
        if(x[0] == b && x[1] == c)return true;
        if(x[0] == c && x[1] == b)return true;
        if(x[0] == a && x[1] == c)return true;
        if(x[0] == c && x[1] == a)return true;
    }
    return false;
}

vector<vector<int>> threeSum(vector<int>& nums ){
    arr_sorted = nums;
    int n = nums.size();
    sort(arr_sorted.begin(), arr_sorted.end());
    
    for(auto x : arr_sorted){
        if(x > 0){
            pos.push_back(x);
        }
        else{
            neg.push_back(x);
        
        }
    }

    for(int i  =0; i < neg.size(); i++){
        for(int j = pos.size()-1; j >= 0; j--){
        int key = -(neg[i] + pos[j]);
        cout<< key << '\n';
        auto ptr = key > 0 ? &pos: &neg;
        int index_of_third_element = binarysearch(*ptr, key, key > 0 ? 0 : i== neg.size() ? i : (i+1) , key > 0 ? j ==0? j: (j-1): neg.size());
        // cout << "i : " << i <<  ", j : " << j << "\n";
        // cout << "index  : " << index_of_third_element <<"\n";   
        if(index_of_third_element == -1){
            continue;
        }
        if(check_triplet_already_present(neg[i], pos[j], (*ptr)[index_of_third_element]))continue;
        vector<int> triplet {neg[i], pos[j], (*ptr)[index_of_third_element]};
        ans.push_back(triplet);
        }
    } 
    return ans;
}

int main(){
    vector<int> nums {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);
    for(auto x : ans){
        cout << "[ " << x[0] << ", " << x[1] << ", "<< x[2] << " ]"; 
    }
    return 0;
}

