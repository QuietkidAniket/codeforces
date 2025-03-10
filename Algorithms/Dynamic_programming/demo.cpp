#include <math.h>
#include <stdio.h>
#include <iostream>
#include<ctime>
using  namespace std;
/* Function to sort an array 
   using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
  
        /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionsort(int arr[], int n)    
{    
    int i, j, small;    
        
    for (i = 0; i < n-1; i++)    // One by one move boundary of unsorted subarray    
    {    
        small = i; //minimum element in unsorted array    
            
        for (j = i+1; j < n; j++)    
        if (arr[j] < arr[small])    
            small = j;    
// Swap the minimum element with the first element    
    int temp = arr[small];    
    arr[small] = arr[i];    
    arr[i] = temp;    
    }    
}    

void bubble_sort(int arr[], int n) {  
  int i, j;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
      if (arr[j] > arr[j + 1]) {  
        int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
      }  
    }  
  }  
}  

void min_max(int a[], int n){
    int min = a[0];
    int max = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<min)
            min = a[i];
        if(a[i]>max)
            max = a[i];

    }
}
void linear_search(int arr[], int n, int key){
    int ans = 0;
    for(int i =0 ;i < n;i++){
        if(key == arr[i]){
            ans = i;
            break;
        }
    }
}
  

  
// Driver code
int main()
{   
    double ans[10];
    int input_size[]  = {
        10000,
        15000,
        20000,
        25000,
        50000,
        70000,
        90000,
        100000,
        125000,
        150000,
    };
    for(int i = 0 ;i < 10; i++){
    int n = input_size[i];
    
    int arr[n]; // = {12, 11, 13, 5, 6};

    for(int i = 0 ; i < n; i++){
        arr[i] = (int)rand() % 100;
    }
    clock_t tStart = clock();
    
    int key =arr[n-1];
    insertionSort(arr, n);
        //  number of clock ticks elapsed since an epoch related to the particular program execution
    // divide by CLOCKS_PER_SEC to get number of seconds taken
    double time1=(double)(clock() - tStart)/CLOCKS_PER_SEC;
    ans[i] = time1;

    }
    for(const auto& time : ans){
        printf("%.6f\n", time);
    }
    return 0;
}