#include "maximum_subarray.h"

int* find_max_crossing_subarray(int* arr, int low, int mid, int high ){
    int* ans = new int[3];
    int left_sum = 0;
    int sum = 0;
    int max_left = -1;
    for(int i = mid; i >= low; i--){
        sum += arr[i];
        if(left_sum < sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    int right_sum = 0;
    int max_right = -1;
    for(int j = mid+1; j <= high; j++){
        sum += arr[j];
        if(right_sum < sum){
            right_sum = sum;
            max_right = j;
        }
    }
    ans[0] = max_left; ans[1] = max_right; ans[2] = left_sum + right_sum;
    return ans;
}   

int* find_max_subarray(int* arr, int low, int high){
    
    int* left_data = new int[3];
    int* cross_data = new int[3];
    int* right_data = new int[3];
    // base case
    if(high == low){
        int* ans = new int[3];
        ans[0] = low; ans[1] = high; ans[2] = arr[low];
        return ans;
        
    }else{
        int mid = (high+low)/2;
        left_data = find_max_subarray(arr, low, mid);
        right_data = find_max_subarray(arr, mid+1, high);
        cross_data = find_max_crossing_subarray(arr, low, mid, high);
        if(left_data[2] > right_data[2] && left_data[2] > cross_data[2]){
            return left_data;
        }else if(right_data[2] > left_data[2] && right_data[2] > cross_data[2]){
            return right_data;
        }else
        {
            return cross_data;
        }
        
        
        
    }

}
