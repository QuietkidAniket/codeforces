#include <bits/stdc++.h>
using namespace std;

void solve();
struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }

    void increaseEnd(){
        cntEndWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void deleteEnd(){
        cntEndWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    
};


class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }
    // O(n) | n is the length of the word
    void insert(string word){
        Node* node = root;
        for(int i = 0 ; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix(); 
        }
        node->increaseEnd();
    }
    
    // O(n) | n is the length of the word
    bool search(string word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->cntEndWith > 0;
    }

    // O(n) | n is the length of the word
    bool startsWith(string prefix){
        Node* node= root;
        for(int i = 0 ; i< prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }


    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0 ; i < word.size(); i++)
        {
            if(!node->containsKey(word[i]))return 0;
            node= node->get(word[i]);
        }    
        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i < word.size(); i++){
            if(!node->containsKey(word[i]))return 0;
            node = node->get(word[i]);
        }
        return node->cntPrefix;
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0;i < word.size(); i++){
            if(!node->containsKey(word[i]))return;
            else{
                node->reducePrefix();
                node = node->get(word[i]);
            }
        }
        node->deleteEnd();
    }

};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    int tt = clock();
    #endif
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
    #endif
    return 0;
}



void solve(){
    
    
    
}