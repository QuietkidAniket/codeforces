#include <iostream>
#include <algorithm>

// mimics the nodes of a Linked List
struct singly_II_node{
    int data;
    singly_II_node* next;
};

// container class which mimics Linked List
class singly_II{
    public:
        using node = singly_II_node;
        using node_ptr = node*;
    private:
        node_ptr head;
    public:
    singly_II() = default;
    // deep copy constructor
    singly_II(const singly_II& other): head(NULL) {
        if(other.head){
            head = new node;
            auto cur= head;
            auto it = other.begin();
            while(true){
                cur->data = *it;

                // advancing the iterator copy by one step
                auto tmp = it;
                ++tmp;
                if(tmp == other.end())break;
                
                // creating a new node and placing the head on it 
                cur->next = new node;
                cur = cur->next;
                
                // replacing the previous iterator with the new iterator copy which is one step forward
                it = tmp;
            }
        }
    }
    // initializer list constructor
    singly_II(const std::initializer_list<int>& ilist): head(NULL) {
        for(auto it = std::rbegin(ilist); it != std::rend(ilist); it++){
            push_front(*it);
        }
    }

    void push_front(int val){
        auto new_node = new node{val, NULL};
        if(head != NULL){
            new_node->next = head;
        }
        head = new_node;
    }
    void pop_front(){
        auto first = head;
        if(head){
            head= head->next;
            delete first;
        }else{
            throw std::out_of_range("Empty List");
        }
    }

        // iterator class for the singly_II container class
        class singly_II_iterator{
            private:
                singly_II::node_ptr ptr;
            public:
                singly_II_iterator(singly_II::node_ptr p): ptr{p} {}
                int& operator*(){
                    return ptr->data;
                }
                singly_II::node_ptr get(){
                    return ptr;
                }
                singly_II_iterator& operator++(){ // pre increment
                    ptr = ptr->next;
                    return *this;
                }
                singly_II_iterator operator++(int){ // post increment
                    singly_II_iterator result = *this;
                    ++(*this);
                    return result;
                }
                friend bool operator==(const singly_II_iterator& left, const singly_II_iterator& right){
                    return left.ptr == right.ptr;
                }
                friend bool operator!=(const singly_II_iterator& left, const singly_II_iterator& right){
                    return left.ptr != right.ptr;
                }   
        };  

    // iterator specific functions
    singly_II_iterator begin(){
        return singly_II_iterator(head);
    }
    singly_II_iterator end(){
        return singly_II_iterator(NULL);
    }
    singly_II_iterator begin() const {
        return singly_II_iterator(head);
    }
    singly_II_iterator end() const {
        return singly_II_iterator(NULL);
    }



};


