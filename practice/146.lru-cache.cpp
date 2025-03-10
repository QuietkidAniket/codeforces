/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class node{
        public:
        int key, val;
        node* next;
        node* prev;
        node(int _key, int _val): key(_key), val(_val) {}
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    unordered_map<int, node*> m;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertnode(node* newnode){
        node* temp = head->next;
        head->next = newnode;
        newnode->next = temp;
        newnode->prev = head;
        temp->prev = newnode;
    }

    void deletenode(node* delnode){
        node* prev = delnode->prev;
        node* next = delnode->next;
        prev->next = next;
        next->prev = prev;
    }
    
    int get(int key_) {
        if(m.find(key_) != m.end()){
            node* resnode = m[key_];
            m.erase(key_);
            deletenode(resnode);
            insertnode(resnode);
            m[key_] = head->next;
            return resnode->val;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()){
            node* curr= m[key_];
            m.erase(key_);
            deletenode(curr);
        }
        if(cap  ==  m.size()){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        insertnode(new node(key_, value));
        m[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

