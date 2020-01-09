/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include "INCLUDE.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //迭代
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* temp = root;
        while(temp || !st.empty())
        {
            while(temp){
                res.push_back(temp->val);
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            temp = temp->right;   
        }
        return res;
    }
};
// @lc code=end
//递归
/*
void helper(vector<int>& res,TreeNode* root){
        if(!root) return;
        res.push_back(root->val);
        helper(res,root->left);
        helper(res,root->right);
    }
    */
