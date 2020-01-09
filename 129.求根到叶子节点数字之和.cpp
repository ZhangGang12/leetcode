/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int temp = 0;
        helper(root,res,temp);
        return res;
    }

    void helper(TreeNode* root, int& res, int temp){
        if(!root) return;
        temp = temp*10 + root->val;
        if(!root->left && !root->right) {
            res += temp;
            return;
        }
        if(root->left) helper(root->left,res,temp);
        if(root->right) helper(root->right,res,temp);
    }

};
// @lc code=end

