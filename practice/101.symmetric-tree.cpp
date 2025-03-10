/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start

// #include <bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };


class Solution {
public:
    void postorder(TreeNode* root, queue<int>&q){
       if(root == NULL)return;

        q.push(root->val);
        postorder(root->left,q);
        postorder(root->right,q); 
    }
    void preorder(TreeNode* root, queue<int>& q){
        if(root == NULL)return;

        q.push(root->val);
        preorder(root->left,q);
        preorder(root->right,q);
    }
    bool isSymmetric(TreeNode* root) {
        queue<int> q1;
        queue<int> q2;
        preorder(root->left, q1);
        postorder(root->right, q2);
        while(!q1.empty() && !q2.empty()){
            if(q1.front() == q2.front())return false;
            q1.pop(), q2.pop();
        }
        if(!q1.empty() || !q2.empty())return false;
        return true;
    }
};
// @lc code=end

