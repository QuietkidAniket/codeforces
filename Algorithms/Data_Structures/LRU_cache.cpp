#include <bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
    class node{
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);

    int cap;
    unordered_map<int, node*> m;
    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode){
        node* temp  = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* newnode){
        node* prev = newnode->prev;
        node* next = newnode->next;
        prev->next = next;
        next->prev = prev;
    }

    int get(int key_){
        if(m.find(key_) != m.end()){
            node* resnode =  m[key_];
            m.erase(key_);  // remove the current address of the key node
            deletenode(resnode);
            addnode(resnode);   
            m[key_] = head->next;  // assign new address of the key node
            return resnode->val;
        }
        return -1;
    }

    int put(int key_, int value){
        if(m.find(key_) != m.end()) {
            node* curr = m[key_];
            m.erase(key_);
            deletenode(curr);
        }
        if(m.size() == cap){ // if the DLL is full
            // remove the least used key
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        // add new node (both above cases need the addition of a new node to head)
        addnode(new node(key_, value));
        m[key_]  = head->next; // assign the new address
    }
};