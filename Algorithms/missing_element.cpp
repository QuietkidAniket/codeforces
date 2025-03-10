#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

int missing_element(const std::vector<int> arr, int n){
    // std::unordered_map<int, int> record;
    // for(int i = 0; i < length-1; i++){
    //     record[arr[i]] = 1;
    // }
    // for(int i = 1; i <= length; i++){
    //     if(!record[i])return i;
    // }
    // return -1;
    
    int true_sum = n * (n+1)/2;
    int observed_sum = std::accumulate(arr.begin(), arr.end(), 0);
    return true_sum - observed_sum;

}

int main(){
    std::vector<int> arr = {5,2,3,4,8,1,10,7,6,11};
    std::cout << "answer : " << missing_element(arr, arr.size()+1) <<'\n';
}