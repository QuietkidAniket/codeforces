#include <iostream>
#include <list>

void print_list(const std::list<int> l){    
    for(auto x: l){
        std::cout <<  x << ' ';
    }
    std::cout <<std::endl;
}

int main(){
    std::list<int> list1= {1,2,3,4,5};
    list1.push_back(6);
    print_list(list1);

    list1.emplace_front(0);
    print_list(list1);

    
    list1.insert(find(list1.begin(), list1.end(), 3), 5);
    print_list(list1);

    list1.insert(next(list1.begin()),2);
    print_list(list1);

    list1.insert(list1.end(), 7);
    print_list(list1);

    list1.pop_back();
    print_list(list1);

    auto it = list1.begin();
    list1.erase(list1.begin(), next(it, 2));
    print_list(list1);

    list1.remove_if([](const int& a){ return a == 5; });
    print_list(list1);

    return 0;
    
}