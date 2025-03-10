#include <iostream>
#include "heap_ds.h"


int main(){
    int arr[9] = {5,13,2,25,7,17,20,8,4};
    printf("Before Sorting : \n");
    for(auto x : arr){
        cout<< x << ' ';
    }
    cout << '\n';
    printf("After sorting using Heapsort Algorithm : \n");
    heapsort(arr, 9);
    for(auto x : arr){
        cout<< x << ' ';
    }
    cout << '\n';
    return 0;
}
