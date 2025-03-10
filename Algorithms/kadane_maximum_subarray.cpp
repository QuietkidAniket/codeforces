#include <iostream>
#include <limits>

// Kadane's Algorithm for the longest maximum subarray problem
// runs in Θ(n) worst case time complexity

int max_subarray(int* arr, int length){
    // keeps track of the sum of a subarray
    int sum {0};

    // keeps track of the maximum value of sum which occured while traversing the entire array
    int best{0};
    
    // pointer to traverse the array
    int i {0};

    while(++i < length){
        // either a new element is appended to the subarray for sum,
        // or a new subarray starts from the element in case addition
        // of the new element to the previous subarray will diminish the element's value
        sum = std::max(arr[i], sum + arr[i]);

        // updated to keep track of the largest occuring value of sum
        best = std::max(best, sum);
    }
    return best;
}

int main(){
    int arr[9] {4,-6,2,-4,16,-9,10,2,5};
    std::cout << max_subarray(arr, 9);
}
