#ifndef HEAPDEMO
#define HEAPDEMO
#include <limits>
using namespace std;

// returns the parent node's index of the given node at i
inline int Parent(const int index){
    // i / 2
    return index >> 1;
}
// returns the child node at left of the given node at i
inline int Left(const int index){
    // 2i
    return (index << 1) +1;
}
// returns the child node at right of the given node at i
inline int Right(const int index){
    // 2i + 1
    return (index << 1) + 2;
}



// Causes a node and its children satisfy the max heap property, O(logn) -> as height of a heap tree is ⌈logn⌉
inline void max_heapify(int arr[], const int heap_size, const int index){
    // left child node index
    int l {Left(index)};
    // right child node index
    int r {Right(index)};

    // used for storing the index of node containing the largest number
    int largest {index};

    // largest of the elements arr[i], arr[l] and arr[r] is determined and its index is stored in largest
    if(l < heap_size && arr[l] > arr[largest]) largest = l;
    if(r < heap_size && arr[r] > arr[largest]) largest = r;

    /*
    if arr[i] is largest then heap is already a max heap and the procedure is terminated.
    otherwise then one of the two children has the largest element.
    and arr[i] is swapped with arr[largest] -  which causes node i and its children (only left and right ones)
    to satisfy the max heap property
    but node largest is however now has the original value arr[i] 
    and the subtree located at node largest might violate the max heap property.
    hence calling maxheap() recursively on node largest (on the subtree of largest)
    */
    if(largest != index){
        swap(arr[index], arr[largest]);
        max_heapify(arr, heap_size, largest);
    }
}
// transforms the given array into a max heap , O(logn) -> tight bound
inline void build_max_heap(int arr[], const int heap_size){
    for(int i = Parent(heap_size) - 1; i >=0 ; i--){
        max_heapify(arr, heap_size, i);
    }
}

// sorts the given array using heapsort algorithm in O(n * logn)
inline void heapsort(int arr[], const int length){
    build_max_heap(arr, length);

    for(int i = length-1; i >=0 ; i--){
        swap(arr[0], arr[i]);
        max_heapify(arr, i,0);
    }
}

#endif