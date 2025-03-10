#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        next= nullptr;
    }
};

void solve();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("/Users/aniketkundu12072004/Algorithms/input.in", "r+", stdin);
    freopen("/Users/aniketkundu12072004/Algorithms/output.out", "w", stdout);
    #endif
    solve();
    
    
    return 0;
}
void solve(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* temp = a ;
    a  = b;
    b = temp;
    cout << a->val << ", " << b->val << '\n';
    
}