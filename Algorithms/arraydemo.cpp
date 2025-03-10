#include <iostream>
#include <array>

// making the data type and the size of the array templatized for the function
template<typename T ,size_t N>
void print_arr(const std::array<T, N>& arr){
    for(const auto x : arr){
        std::cout << x <<  "\n";
    }
}

template<typename T, size_t N>
void print_arr_rev(const std::array<T, N>& arr){
    for(auto i = arr.rbegin(); i != arr.rend(); i++)
    {   
        std::cout << *i << "\n";
    }
}


int main()
{
    std::array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    std::cin >> n;
    try
    {   // array.at() method raises out_of_range exception when index is out of range
        std::cout << "Element at " << n << "th position : "<< arr.at(n) << '\n';
    }
    catch (const std::out_of_range exception)
    {
        std::cout << "Index out of range, Exception : " << exception.what() << '\n';
    }

    print_arr(arr);
    print_arr_rev(arr);

}
